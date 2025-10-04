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

  const restaurants = names.map((name, idx) => {
    const query = encodeURIComponent(name + ' mumbai restaurant food');
    // larger image for detail cards, thumbnail for lists
    const imgLarge = `https://source.unsplash.com/1200x800/?${query}&sig=${idx + 1}`;
    const imgThumb = `https://source.unsplash.com/400x300/?${query}&sig=${idx + 101}`;
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
