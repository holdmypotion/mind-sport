
struct grid {
  int n, m;
  vector<string> adj;
  vvb vis;

  int dr[4] = { 0, 0, 1, -1 };
  int dc[4] = { 1, -1, 0, 0 };
  string ds = "RLDU";

  grid() = default;
  grid(int n, int m) : n(n), m(m) {
    adj.resize(n);
    vis.resize(n, vb(m, false));
  }

  //! Customize according to question
  void fillgrid() {
    for (auto& ele : adj) cin >> ele;

    forn(i, n) {
      forn(j, m) {
        // ! Customize
      }
    }
  }

  bool isValid(int x, int y) {
    bool possible = (x < n&& x >= 0 && y < m&& y >= 0);
    // ! Customize
    if (!possible || vis[x][y] || adj[x][y] == 0) return false;
    return true;
  }
};
