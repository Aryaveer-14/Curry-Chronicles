const fs = require('fs');
const pool = require('./db');

(async function(){
  try {
    const raw = fs.readFileSync('ratings.json','utf8');
    const data = JSON.parse(raw || '{}');
    const conn = await pool.getConnection();
    try {
      await conn.beginTransaction();
      for (const [restId, arr] of Object.entries(data)) {
        if (!Array.isArray(arr) || arr.length === 0) continue;
        for (const r of arr) {
          await conn.execute('INSERT INTO ratings (restaurant_id, rating) VALUES (?, ?)', [restId, r]);
        }
      }
      await conn.commit();
      console.log('Migration complete');
    } catch (err) {
      await conn.rollback();
      console.error('Migration failed', err);
    } finally {
      conn.release();
    }
  } catch (err) {
    console.error('Failed to read ratings.json or DB error', err);
  } finally {
    process.exit(0);
  }
})();
