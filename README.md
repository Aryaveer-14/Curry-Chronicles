# Live Ranking — Local Dev

This small project contains a front-end `live-ranking.html` and a tiny Node/Express backend (`server.js`) to aggregate ratings for the top 100 Mumbai restaurants.

What the app does
- Displays 100 curated Mumbai restaurants with images (Unsplash).
- Lets users rate each restaurant on a 1–10 scale.
- Attempts to POST ratings to a local backend and GET aggregated stats so rankings become "live" across devices on the same network.
- Falls back to `localStorage` if the backend is not available so the page remains functional.

Quick run (local development)
1. Install dependencies for the backend:

```powershell
cd "c:\Users\aryav\Desktop\html2"
npm install
```

2. Start the backend server:

```powershell
npm start
```

The server listens on http://localhost:3000 by default.

3. Open the UI:
- You can open `live-ranking.html` directly in the browser, but to allow same-origin API calls it's easier to serve the static files. Two quick options:

Option A — Serve with the backend (same origin):
- Modify `server.js` to serve static files from the project root by uncommenting or adding `app.use(express.static(__dirname));` near the top. Then restart the server and visit http://localhost:3000/live-ranking.html

Option B — Small static server (recommended when testing):
- Use a simple static server (e.g., `npx http-server` or `npx serve`) from the project folder:

```powershell
npx http-server -p 8080
# then open http://localhost:8080/live-ranking.html
```

Notes about development helper tools
- The `package.json` includes a `dev` script (`nodemon server.js`) for automatic restarts during development. Install nodemon as a dev dependency if you want to use it:

```powershell
npm install --save-dev nodemon
```

The server now serves static files from the project root so you can visit http://localhost:3000/live-ranking.html after running `npm start`.

Notes
- `ratings.json` stores all ratings as a simple map of arrays per restaurant id. It's used only for local development.
- The `/api/reset` endpoint is intentionally not secure — it's only for convenience while testing.

If you want, I can:
- Add static file serving directly to `server.js` and a `npm run dev` script.
- Start the server here and run a smoke test (I can run terminal commands for you).
- Add UI polish: toasts, disabled buttons after submit, or prevent duplicate submissions per session.
