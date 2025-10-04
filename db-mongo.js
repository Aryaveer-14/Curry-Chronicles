const { MongoClient, ObjectId } = require('mongodb');

const MONGO_URI = process.env.MONGO_URI || 'mongodb://localhost:27017';
const MONGO_DB = process.env.MONGO_DB || 'currychronicles';

let client = null;
let db = null;

async function connect() {
  if (db) return db;
  client = new MongoClient(MONGO_URI, { useNewUrlParser: true, useUnifiedTopology: true });
  await client.connect();
  db = client.db(MONGO_DB);
  // ensure indexes
  await Promise.all([
    db.collection('ratings').createIndex({ restaurant_id: 1 }),
    db.collection('reviews').createIndex({ restaurant_id: 1 }),
    db.collection('images').createIndex({ restaurant_id: 1 }),
    db.collection('restaurants').createIndex({ id: 1 }, { unique: true, sparse: true })
  ]).catch(()=>{});
  return db;
}

async function insertRating(restaurant_id, rating) {
  const d = await connect();
  return d.collection('ratings').insertOne({ restaurant_id, rating: Number(rating), created_at: new Date() });
}

async function insertReview(restaurant_id, scores, avg, comment) {
  const d = await connect();
  const doc = { restaurant_id, scores, avg: Number(avg), comment: comment || null, created_at: new Date() };
  return d.collection('reviews').insertOne(doc);
}

async function getStats() {
  const d = await connect();
  const reviewsColl = d.collection('reviews');
  const ratingsColl = d.collection('ratings');

  // Prefer reviews aggregation if reviews exist
  const reviewCount = await reviewsColl.countDocuments();
  if (reviewCount > 0) {
    const pipeline = [
      { $group: {
        _id: '$restaurant_id',
        count: { $sum: 1 },
        avg: { $avg: '$avg' },
        food_avg: { $avg: '$scores.food' },
        service_avg: { $avg: '$scores.service' },
        ambience_avg: { $avg: '$scores.ambience' },
        time_avg: { $avg: '$scores.time' },
        accessibility_avg: { $avg: '$scores.accessibility' }
      }},
    ];
    const rows = await reviewsColl.aggregate(pipeline).toArray();
    const stats = {};
    rows.forEach(r => {
      stats[r._id] = {
        count: Number(r.count),
        avg: Number(r.avg),
        breakdown: {
          food: r.food_avg != null ? Number(r.food_avg) : null,
          service: r.service_avg != null ? Number(r.service_avg) : null,
          ambience: r.ambience_avg != null ? Number(r.ambience_avg) : null,
          time: r.time_avg != null ? Number(r.time_avg) : null,
          accessibility: r.accessibility_avg != null ? Number(r.accessibility_avg) : null,
        }
      };
    });
    return stats;
  }

  // Fallback to ratings collection
  const pipeline2 = [
    { $group: { _id: '$restaurant_id', count: { $sum:1 }, avg: { $avg: '$rating' } } }
  ];
  const rows2 = await ratingsColl.aggregate(pipeline2).toArray();
  const stats2 = {};
  rows2.forEach(r => { stats2[r._id] = { count: Number(r.count), avg: Number(r.avg) }; });
  return stats2;
}

async function resetRatings() {
  const d = await connect();
  await Promise.all([
    d.collection('ratings').deleteMany({}),
    d.collection('reviews').deleteMany({})
  ]);
  return true;
}

async function rawDump() {
  const d = await connect();
  const reviews = await d.collection('reviews').find({}).toArray();
  const ratings = await d.collection('ratings').find({}).toArray();
  return { reviews, ratings };
}

module.exports = {
  connect,
  insertRating,
  insertReview,
  getStats,
  resetRatings,
  rawDump,
  _client: () => client
};
