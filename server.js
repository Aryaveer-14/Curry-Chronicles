const express = require('express');
const fs = require('fs');
const path = require('path');
const bodyParser = require('body-parser');
const cors = require('cors');

const app = express();
const PORT = process.env.PORT || 3000;
const DATA_FILE = path.join(__dirname, 'ratings.json');

app.use(cors());
app.use(bodyParser.json());

// Serve static files from project root so front-end and API can be same-origin
app.use(express.static(__dirname));

// --- Simple admin token system (in-memory) ---
const crypto = require('crypto');
const ADMIN_TOKENS = new Map(); // token -> { user, expires }
const ADMIN_TTL_MS = 1000 * 60 * 60; // 1 hour

function generateToken() {
  return crypto.randomBytes(24).toString('hex');
}

function validateAdminToken(token) {
  if (!token) return false;
  const rec = ADMIN_TOKENS.get(token);
  if (!rec) return false;
  if (rec.expires < Date.now()) { ADMIN_TOKENS.delete(token); return false; }
  return true;
}

function requireAdmin(req, res, next) {
  const auth = req.headers.authorization || '';
  let token = null;
  if (auth.startsWith('Bearer ')) token = auth.slice('Bearer '.length).trim();
  if (!token && req.query && req.query.token) token = req.query.token;
  if (!validateAdminToken(token)) return res.status(401).json({ error: 'Unauthorized' });
  req.adminToken = token;
  next();
}

// Admin login endpoint (must set ADMIN_USER and ADMIN_PASS in env)
app.post('/admin/login', (req, res) => {
  const { username, password } = req.body || {};
  const confUser = process.env.ADMIN_USER;
  const confPass = process.env.ADMIN_PASS;
  if (!confUser || !confPass) return res.status(500).json({ error: 'Admin credentials not configured on server. Set ADMIN_USER and ADMIN_PASS.' });
  if (!username || !password || username !== confUser || password !== confPass) return res.status(401).json({ error: 'Invalid credentials' });
  const token = generateToken();
  ADMIN_TOKENS.set(token, { user: username, expires: Date.now() + ADMIN_TTL_MS });
  return res.json({ success: true, token, ttl: ADMIN_TTL_MS });
});

app.post('/admin/logout', requireAdmin, (req, res) => {
  const t = req.adminToken; if (t) ADMIN_TOKENS.delete(t);
  res.json({ success: true });
});

// Return raw stored data (file-based) or indicate DB mode
app.get('/admin/raw', requireAdmin, async (req, res) => {
  if (useMongo) {
    try { const dump = await mongo.rawDump(); return res.json({ source: 'mongo', data: dump }); } catch(err){ console.warn('Mongo raw dump failed', err); }
  }
  if (useDb && dbPool) {
    // Best-effort: if DB is used, dump reviews table if exists, otherwise fall back
    try {
      const [rows] = await dbPool.query('SELECT * FROM reviews');
      return res.json({ source: 'db_reviews', data: rows });
    } catch (e) {
      try {
        const [rows2] = await dbPool.query('SELECT * FROM ratings');
        return res.json({ source: 'db_ratings', data: rows2 });
      } catch (err) {
        // fall through to file-based
        console.warn('DB raw dump failed, falling back to file', err.message || err);
      }
    }
  }
  const data = readData();
  return res.json({ source: 'file', data });
});

// initialize data file if missing
if (!fs.existsSync(DATA_FILE)) {
  fs.writeFileSync(DATA_FILE, JSON.stringify({}), 'utf8');
}

let useDb = false;
let dbPool = null;
let useMongo = false;
let mongo = null;
if (process.env.USE_DB === 'true') {
  try {
    dbPool = require('./db');
    useDb = true;
    console.log('Using MySQL database for ratings');
  } catch (e) {
    console.warn('MySQL DB pool load failed, falling back to file storage', e);
    useDb = false;
  }
}
if (process.env.USE_DB === 'mongo') {
  try {
    mongo = require('./db-mongo');
    mongo.connect().then(()=> console.log('Connected to MongoDB')).catch(err=> console.warn('MongoDB connect failed', err));
    useMongo = true;
    useDb = false; // prioritize mongo when explicitly requested
  } catch (e) {
    console.warn('MongoDB adapter load failed, falling back to file storage', e);
    useMongo = false;
  }
}

function readData() {
  try {
    const raw = fs.readFileSync(DATA_FILE, 'utf8');
    return JSON.parse(raw || '{}');
  } catch (e) {
    console.error('readData error', e);
    return {};
  }
}

function writeData(data) {
  try {
    fs.writeFileSync(DATA_FILE, JSON.stringify(data, null, 2), 'utf8');
  } catch (e) {
    console.error('writeData error', e);
  }
}

// Submit a rating for a restaurant
// POST /api/rate { id: 'r1', rating: 7 }
app.post('/api/rate', async (req, res) => {
  const { id, rating } = req.body;
  if (!id || typeof rating !== 'number' || rating < 1 || rating > 10) {
    return res.status(400).json({ error: 'Invalid payload' });
  }

  if (useMongo) {
    try { await mongo.insertRating(id, rating); return res.json({ success: true }); } catch(err){ console.error('Mongo insertRating failed', err); }
  } else if (useDb && dbPool) {
    try {
      await dbPool.execute('INSERT INTO ratings (restaurant_id, rating) VALUES (?, ?)', [id, rating]);
      return res.json({ success: true });
    } catch (err) {
      console.error('DB insert error', err);
      // fall through to file-based fallback
    }
  }

  // file-based fallback
  const data = readData();
  if (!data[id]) data[id] = [];
  data[id].push(rating);
  writeData(data);
  return res.json({ success: true });
});

// Submit a detailed review with multiple category scores
// POST /api/review { id: 'r1', scores: { food:8, service:9, ambience:7, time:8, accessibility:9 } }
app.post('/api/review', async (req, res) => {
  const { id, scores } = req.body;
  if (!id || typeof scores !== 'object' || scores === null) {
    return res.status(400).json({ error: 'Invalid payload' });
  }
  const cats = ['food','service','ambience','time','accessibility'];
  const vals = [];
  for (const c of cats) {
    const v = Number(scores[c]);
    if (!v || isNaN(v) || v < 1 || v > 10) return res.status(400).json({ error: `Invalid score for ${c}` });
    vals.push(v);
  }
  const avg = vals.reduce((s,v)=>s+v,0)/vals.length;
  // Prepare a review object (detailed)
  const comment = typeof req.body.comment === 'string' ? req.body.comment.trim() : null;
  const review = { scores: {}, avg, comment, ts: Date.now() };
  cats.forEach((c,i)=> review.scores[c] = vals[i]);

  // Try to persist in DB with a 'reviews' table (best-effort). Also keep legacy ratings table insert for compatibility.
  if (useDb && dbPool) {
  if (useMongo) {
    try { await mongo.insertReview(id, review.scores, review.avg, review.comment); } catch(err){ console.error('Mongo insertReview failed', err); }
  } else if (useDb && dbPool) {
    try {
      // Try to write to a reviews table (restaurant_id, food, service, ambience, time, accessibility, avg, comment, created_at)
      await dbPool.execute(
        'INSERT INTO reviews (restaurant_id, food, service, ambience, time, accessibility, avg, comment, created_at) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)',
        [id, review.scores.food, review.scores.service, review.scores.ambience, review.scores.time, review.scores.accessibility, review.avg, review.comment, new Date()]
      );
    } catch (err) {
      // if reviews table doesn't exist or insert fails, log and continue — we'll still insert into the legacy ratings table below
      console.warn('DB reviews insert failed (continuing with legacy insert):', err.message || err);
    }

    try {
      // keep inserting the avg into legacy ratings table so older aggregates still work
      await dbPool.execute('INSERT INTO ratings (restaurant_id, rating) VALUES (?, ?)', [id, avg]);
    } catch (err) {
      console.error('DB review legacy insert error', err);
      // fall through to file fallback
    }
  }
  }

  // file-based fallback: store detailed review objects (prefer object entries but tolerate legacy numbers too)
  const data = readData();
  if (!data[id]) data[id] = [];
  data[id].push(review);
  writeData(data);
  return res.json({ success: true, avg });
});

// Get aggregated stats for all restaurants
// GET /api/stats -> { r1: { count: n, avg: x }, ... }
app.get('/api/stats', async (req, res) => {
  // Try DB first: prefer aggregated data from 'reviews' table (which contains per-category fields) if available
  if (useDb && dbPool) {
  if (useMongo) {
    try { const s = await mongo.getStats(); return res.json(s); } catch(err){ console.error('Mongo getStats failed', err); }
  }
  if (useDb && dbPool) {
    try {
      // If a reviews table exists, aggregate per-category averages
      const [rows] = await dbPool.query(`
        SELECT
          restaurant_id,
          COUNT(*) AS count,
          AVG(avg) AS avg,
          AVG(food) AS food_avg,
          AVG(service) AS service_avg,
          AVG(ambience) AS ambience_avg,
          AVG(time) AS time_avg,
          AVG(accessibility) AS accessibility_avg
        FROM reviews
        GROUP BY restaurant_id
      `);
      if (rows && rows.length) {
        const stats = {};
        rows.forEach(r => {
          stats[r.restaurant_id] = {
            count: Number(r.count),
            avg: Number(r.avg),
            breakdown: {
              food: r.food_avg !== null ? Number(r.food_avg) : null,
              service: r.service_avg !== null ? Number(r.service_avg) : null,
              ambience: r.ambience_avg !== null ? Number(r.ambience_avg) : null,
              time: r.time_avg !== null ? Number(r.time_avg) : null,
              accessibility: r.accessibility_avg !== null ? Number(r.accessibility_avg) : null,
            }
          };
        });
        return res.json(stats);
      }
      // If reviews table returned no rows, fall back to legacy ratings table
      const [legacyRows] = await dbPool.query(`SELECT restaurant_id, COUNT(*) AS count, AVG(rating) AS avg FROM ratings GROUP BY restaurant_id`);
      const legacyStats = {};
      legacyRows.forEach(r => { legacyStats[r.restaurant_id] = { count: Number(r.count), avg: Number(r.avg) }; });
      return res.json(legacyStats);
    } catch (err) {
      console.error('DB stats error (falling back to file):', err.message || err);
      // fall back to file-based
    }
  }
  }

  // File-based aggregation: support legacy numeric entries (simple averages) and new detailed review objects
  const data = readData();
  const stats = {};
  Object.keys(data).forEach(id => {
    const arr = data[id] || [];
    let count = 0;
    let sumAvg = 0;
    const catSums = { food: 0, service: 0, ambience: 0, time: 0, accessibility: 0 };
    let catCounts = { food: 0, service: 0, ambience: 0, time: 0, accessibility: 0 };

    arr.forEach(entry => {
      if (typeof entry === 'number') {
        // legacy: only avg stored
        count += 1;
        sumAvg += entry;
      } else if (entry && typeof entry === 'object') {
        // detailed review object expected: { scores: {food:..}, avg: .. }
        const avgVal = Number(entry.avg) || 0;
        count += 1;
        sumAvg += avgVal;
        if (entry.scores && typeof entry.scores === 'object') {
          Object.keys(catSums).forEach(c => {
            const v = Number(entry.scores[c]);
            if (!isNaN(v) && v > 0) { catSums[c] += v; catCounts[c] += 1; }
          });
        }
      }
    });

    const avg = count ? (sumAvg / count) : 0;
    const breakdown = {};
    Object.keys(catSums).forEach(c => { breakdown[c] = catCounts[c] ? (catSums[c] / catCounts[c]) : null; });
    stats[id] = { count, avg, breakdown };
  });
  res.json(stats);
});

// Reset all ratings (not secure — for local dev only)
app.post('/api/reset', async (req, res) => {
  if (useMongo) {
    try { await mongo.resetRatings(); return res.json({ success: true }); } catch(err){ console.error('Mongo reset failed', err); }
  }
  if (useDb && dbPool) {
    try {
      await dbPool.query('TRUNCATE TABLE ratings');
      return res.json({ success: true });
    } catch (err) {
      console.error('DB reset error', err);
      // fall back
    }
  }
  writeData({});
  res.json({ success: true });
});

app.listen(PORT, () => {
  console.log(`Live-ranking server listening on http://localhost:${PORT}`);
});
