struct grid {
  int n, m;
  p32 src, dest;
  vv32 adj;
  vvb vis;
  vvp32 parent;
  vector<vector<char>> path;

  int dr[4] = { 0, 0, 1, -1 };
  int dc[4] = { 1, -1, 0, 0 };
  string ds = "RLDU";

  grid() = default;
  grid(int n, int m) : n(n), m(m) {
    parent.resize(n, vp32(m));
    path.resize(n, vector<char>(m));
    adj.resize(n, v32(m, 0));
    vis.resize(n, vb(m, false));
  }

  void fillgrid() {
    forn(i, n) {
      string s; cin >> s;
      forn(j, m) {
        if (s[j] == 'A') {
          src = { i, j };
          adj[i][j] = 1;
        }
        if (s[j] == 'B') {
          dest = { i, j };
          adj[i][j] = 2;
        }
        if (s[j] == '.') adj[i][j] = 1;
      }
    }
  }

  bool isValid(int x, int y) {
    bool possible = (x < n&& x >= 0 && y < m&& y >= 0);
    if (!possible || vis[x][y] || adj[x][y] == 0) return false;
    return true;
  }

  void bfs() {
    queue<p32> q;
    q.push({ src.fi, src.se });
    while (!q.empty()) {
      int x = q.front().fi;
      int y = q.front().se;
      q.pop();
      vis[x][y] = true;
      // if (adj[x][y] == 2) break; // reached destination
      forn(i, 4) {
        int nx = x + dr[i], ny = y + dc[i];
        if (isValid(nx, ny)) {
          q.push({ nx, ny });
          vis[nx][ny] = true;
        }
      }
    }
  }
};

void potion() {
  int n, m; cin >> n >> m;
  grid g(n, m);
  g.fillgrid();

  g.bfs();
}
