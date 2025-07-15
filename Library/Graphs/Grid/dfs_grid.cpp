struct grid {
  int n, m;
  vv32 adj;
  vvb vis;

  int dr[4] = { 0, 0, 1, -1 };
  int dc[4] = { 1, -1, 0, 0 };
  string ds = "RLDU";

  grid() = default;
  grid(int n, int m) : n(n), m(m) {
    adj.resize(n, v32(m, 0));
    vis.resize(n, vb(m, false));
  }

  void fillgrid() {
    forn(i, n) {
      string s; cin >> s;
      forn(j, m) {
        if (s[j] == '.') adj[i][j] = 1;
      }
    }
  }

  bool isValid(int x, int y) {
    bool possible = (x < n&& x >= 0 && y < m&& y >= 0);
    if (!possible || vis[x][y] || adj[x][y] == 0) return false;
    return true;
  }

  void dfs(int x, int y) {
    vis[x][y] = true;
    forn(i, 4) {
      int nx = x + dr[i], ny = y + dc[i];
      if (isValid(nx, ny)) dfs(nx, ny);
    }
  }
};

void potion() {
  int n, m; cin >> n >> m;
  grid g(n, m);
  g.fillgrid();

  int count = 0;
  forn(i, n) {
    forn(j, m) {
      if (g.adj[i][j] && !g.vis[i][j]) {
        g.dfs(i, j);
        count++;
      }
    }
  }

  cout << count;
}
