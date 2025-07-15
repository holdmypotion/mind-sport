
struct graph {
  ll n, m, count = 0;
  vv64 adj;
  vector<bool> vis;
  graph() = default;
  graph(ll n) : n(n) {
    adj.resize(n + 1);
    vis.resize(n + 1, 0);
  };
  graph(ll n, ll m) : n(n), m(m) {
    adj.resize(n + 1);
    vis.resize(n + 1, 0);
  };

  void addEdge(ll u, ll v) {
    adj[u].push_back(v);
  }

  int dfs(ll u, ll dst) {
    if (u == dst) {
      count++;
      return count;
    }
    vis[u] = true;
    for (auto& v : adj[u]) {
      if (!vis[v]) dfs(v, dst);
    }
    vis[u] = false;
    return count;
  }

  int countAllPaths(ll u, ll v) {
    return dfs(u, v);
  }
};

// solution
void potion() {
  ll n, m; cin >> n >> m;
  graph g(n, m);
  forn(i, m) {
    ll u, v; cin >> u >> v;
    g.addEdge(u, v);
  }

  cout << g.countAllPaths(5, 6);
}
