// Optional: place your curated external image URLs here.
// Provide objects with either `id` (e.g. 'r1') or `name` to match restaurants,
// and `imgThumb` and `imgLarge` properties pointing to hosted image URLs.
// Example:
// window.externalImages = [
//   { id: 'r1', imgThumb: 'https://cdn.example.com/thumbs/r1.jpg', imgLarge: 'https://cdn.example.com/large/r1.jpg' },
//   { name: 'Bombay Canteen', imgThumb: 'https://example.com/bc-thumb.jpg', imgLarge: 'https://example.com/bc-large.jpg' }
// ];

// Generate a stable list of external images (Unsplash source URLs) for r1..r100
(() => {
	// Use picsum.photos stable image IDs to provide fixed direct image URLs.
	// Picsum IDs from 10..109 (100 images) - thumbs 400x300, large 1200x800
	const list = [];
	for (let i = 1; i <= 100; i++) {
		const picId = 9 + i; // 10..109
		const imgThumb = `https://picsum.photos/id/${picId}/400/300`;
		const imgLarge = `https://picsum.photos/id/${picId}/1200/800`;
		list.push({ id: `r${i}`, imgThumb, imgLarge });
	}
	window.externalImages = list;
})();


