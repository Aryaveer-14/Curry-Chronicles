// Shared restaurants data for both search and live-ranking pages
// Each item: { id, name, img, location }
(function(){
  const names = [
    "The Table","Bombay Canteen","Bastian","Indigo","Masala Library","Trishna","Gajalee","Britannia & Co.",
    "Leopold Cafe","Cafe Mondegar","Bademiya","Mahesh Lunch Home","Khyber","Sassy Spoon","Fifty Five East","Smoke House Deli",
    "The Bohri Kitchen","The Pantry","O Pedro","The Clearing House","Dome (InterContinental)","Pizza Express (Bandra)","SodaBottleOpenerWala",
    "Prithvi Cafe","Nitin","Wankhede Restaurant","Copper Chimney","Swati Snacks","Wadeshwar","Gaylord","Aaaheli","Tasting Room",
    "Gomantak","Cafe Madras","Shiv Sagar","Kailash","Café Zoe","Yauatcha (Mumbai)","Tamasha","Mamagoto","Hakkasan (Mumbai)","Saffron Spice",
    "Kala Ghoda Cafe","Bungalow 9","Olive Bar & Kitchen","The Blue Door Café","Farzi Café","Bombay Butter Chicken","Rajdhani","Woodside Inn",
    "PizzaByTheBay","Mirchi & Mime","Zaffran","Cafe Landmark","Dakshinayan","Panchvati Gaurav","Antares","Bondi","Cafe Universal","Gaylord (Worli)",
    "Tata Starbucks (Fort)","The Nutcracker","Sequel Bistro & Juice Bar","The Irish House","Oye Kiddan","Britannia & Co. (Ballard Estate)","Bademiya Seekh",
    "Kokum","Nostalgia","Woodlands","Shree Krishna","Gajalee Express","Hakkasan (Lower Parel)","Cafe Basilico","The Bohri Kitchen (Bandra)","Kerala Cafe",
    "Glocal Junction","Bombay Sandwich Co.","Theobroma (Mumbai)","Kokum (Juhu)","Bombay Brasserie","Punjab Grill","Masala & More","Ammi's Biryani","Gajalee - Seafood",
    "The Bombay Post","Sanjay's","Shree Thaker Bhojanalay","The Fish Market"
  ];

  // curated themes to produce a diverse set of images (rotated across restaurants)
  const themes = [
    'indian food','restaurant interior','street food','fine dining','seafood','curry','spices','dessert','chef cooking','plated meal',
    'traditional food','modern restaurant','cozy cafe','coffee','bakery','grill','barbecue','tandoor','vegetarian dish','sweets',
    'salad','noodles','rice','stew','appetizer','cocktails','wine','brunch','dining table','kitchen',
    'food closeup','market food','food plating','rustic food','gourmet','fusion food','regional cuisine','snack','tea','street vendor'
  ];

  const restaurants = names.map((name, idx) => {
    // create a unique SVG placeholder data-URL for each restaurant so images are always visible
    const safeLabel = (name || 'R').split(/\s+/).map(p=>p[0]).join('').toUpperCase().slice(0,3) || `R${idx+1}`;
    const hue = (idx * 37) % 360; // varied hue per restaurant
    const bgLarge = `hsl(${hue} 60% 30%)`;
    const bgThumb = `hsl(${(hue+40)%360} 60% 35%)`;
    function svgDataUrl(text, w, h, bg){
      const svg = `<svg xmlns='http://www.w3.org/2000/svg' width='${w}' height='${h}' viewBox='0 0 ${w} ${h}'><rect width='100%' height='100%' fill='${bg}'/><text x='50%' y='50%' fill='#ffffff' font-family='Inter, Arial, Helvetica, sans-serif' font-weight='600' font-size='${Math.round(Math.min(w,h)/5)}' dominant-baseline='middle' text-anchor='middle'>${text}</text></svg>`;
      return 'data:image/svg+xml;utf8,' + encodeURIComponent(svg);
    }
    const imgLarge = svgDataUrl(safeLabel, 1200, 800, bgLarge);
    const imgThumb = svgDataUrl(safeLabel, 400, 300, bgThumb);
    return {
      id: `r${idx+1}`,
      name,
      imgLarge,
      imgThumb,
      location: 'Mumbai'
    };
  });

  // expose globally
  window.restaurants = restaurants;
})();
