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
	const themes = ['restaurant interior','street food','curry','plated meal','seafood','dessert','chef','spices','cozy cafe','dining table','brunch','grill','barbecue','tandoor','vegetarian dish','fusion food','traditional food','modern restaurant','coffee shop','bakery'];
	const list = [];
	for(let i=1;i<=100;i++){
		const theme = themes[(i-1) % themes.length];
		const q = encodeURIComponent(theme + ' mumbai food');
		const imgThumb = `https://source.unsplash.com/400x300/?${q}&sig=${i+100}`;
		const imgLarge = `https://source.unsplash.com/1200x800/?${q}&sig=${i+200}`;
		list.push({ id: `r${i}`, imgThumb, imgLarge });
	}
	window.externalImages = list;
})();

