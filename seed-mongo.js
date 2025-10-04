// seed-mongo.js
// Populate the `restaurants` collection in MongoDB with id, name, location, imgThumb, imgLarge
const { MongoClient } = require('mongodb');
const fs = require('fs');
const path = require('path');

const MONGO_URI = process.env.MONGO_URI || 'mongodb://localhost:27017';
const MONGO_DB = process.env.MONGO_DB || 'currychronicles';

async function loadNames() {
  const file = path.join(__dirname, 'restaurants-data.js');
  const txt = fs.readFileSync(file, 'utf8');
  const m = txt.match(/const\s+names\s*=\s*\[([\s\S]*?)\]\s*;/);
  if (!m) throw new Error('Could not find names array in restaurants-data.js');
  const arrText = '[' + m[1] + ']';
  // Evaluate safely to produce array (file contains plain string literals)
  // Replace backticks (if any) to strings is unlikely; assume simple quoted strings
  const names = Function(`"use strict"; return ${arrText};`)();
  return names.map(s => String(s));
}

async function main() {
  const client = new MongoClient(MONGO_URI, { useNewUrlParser: true, useUnifiedTopology: true });
  try {
    console.log('Connecting to', MONGO_URI, 'db:', MONGO_DB);
    await client.connect();
    const db = client.db(MONGO_DB);
    const names = await loadNames();
    console.log('Loaded', names.length, 'restaurant names');

    const coll = db.collection('restaurants');
    const ops = [];
    for (let i = 0; i < names.length; i++) {
      const id = `r${i+1}`;
      const name = names[i];
      const picId = 10 + i; // picsum ids 10..(10+names.length-1)
      const imgThumb = `https://picsum.photos/id/${picId}/400/300`;
      const imgLarge = `https://picsum.photos/id/${picId}/1200/800`;
      const doc = { id, name, location: 'Mumbai', imgThumb, imgLarge, created_at: new Date() };
      ops.push({ updateOne: { filter: { id }, update: { $set: doc }, upsert: true } });
    }

    if (ops.length) {
      console.log('Upserting', ops.length, 'restaurant documents...');
      const res = await coll.bulkWrite(ops, { ordered: false });
      console.log('Bulk write result:', res.result || res);
    }

    console.log('Done. Restaurants seeded into collection `restaurants` in', MONGO_DB);
  } catch (err) {
    console.error('Seed failed:', err.message || err);
    process.exitCode = 1;
  } finally {
    await client.close();
  }
}

if (require.main === module) main();
