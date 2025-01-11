struct graph {
  ll n, m;
  vv64 adj;
  queue<ll> q;
  vector<bool> vis;
  graph() = default;
  graph(ll n) : n(n) {
    adj.resize(n + 1);
    vis.resize(n + 1);
  };
  graph(ll n, ll m) : n(n), m(m) {
    adj.resize(n + 1);
    vis.resize(n + 1);
  };

  void addEdge(ll u, ll v) {
    adj[u].pb(v);
  }

  void dfs1(ll u) {
    vis[u] = true;
    for (auto& v : adj[u]) {
      if (!vis[v]) dfs1(v);
    }
    q.push(u);
  }

  void dfs2(ll u) {
    cout << u << " ";
    vis[u] = true;
    for (auto& v : adj[u]) {
      if (!vis[v]) dfs2(v);
    }
  }


  void kosarajuPrint() {
    forsn(i, 1, n + 1) {
      if (!vis[i]) dfs1(i);
    }

    vis.assign(n + 1, 0);
    while (!q.empty()) {
      ll x = q.front(); q.pop();
      if (!vis[x]) {
        dfs2(x);
        cout << ln;
      }
    }
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
  g.kosarajuPrint();

}
