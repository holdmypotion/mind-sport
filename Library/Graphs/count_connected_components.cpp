struct graph {
  ll n, m;
  vv64 adj;
  vector<bool> vis;
  graph() = default;
  graph(ll n) : n(n) {
    adj.resize(n + 1);
    vis.resize(n + 1, false);
  };
  graph(ll n, ll m) : n(n), m(m) {
    adj.resize(n + 1);
    vis.resize(n + 1, false);
  };

  void addEdge(ll a, ll b) {
    adj[a].pb(b);
  }

  void dfs(ll u) {
    vis[u] = true;
    for (auto& v : adj[u]) {
      if (!vis[v]) dfs(v);
    }
  }

  void countConnectedComponents() {
    ll count = 0;
    forsn(i, 1, n + 1) {
      if (!vis[i]) {
        count++;
        dfs(i);
      }
    }
    return count;
  }

};

// solution
void potion() {
  ll n, m; cin >> n >> m;
  graph g(n, m);
  forn(i, m) {
    int a, b; cin >> a >> b;
    g.addEdge(a, b);
    g.addEdge(b, a);
  }
  cout << g.countConnectedComponents();
}
