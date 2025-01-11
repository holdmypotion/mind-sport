struct graph {
  ll n, m;
  v64 adj[max_element];
  vector<bool> vis, dis;
  queue<ll> q;
  graph() = default;
  graph(ll n) : n(n) {
    vis.resize(n + 1, false);
    dis.resize(n + 1, false);
  };
  graph(ll n, ll m) : n(n), m(m) {
    vis.resize(n + 1, false);
    dis.resize(n + 1, false);
  };

  void addEdge(ll a, ll b) {
    adj[a].push_back(b);
  }

  void bfs(ll u) {
    vis[u] = true;
    dis[u] = 0;
    q.push(u);
    while (!q.empty()) {
      auto s = q.front(); q.pop();
      cout << s << " ";
      for (auto v : adj[s]) {
        if (vis[v]) continue;
        vis[v] = true;
        dis[v] = dis[s] + 1;
        q.push(v);
      }
    }
  }
};

void potion() {
  graph g(4, 5);
  forn(i, 5) {

    ll a, b; cin >> a >> b;
    g.addEdge(a, b);
  }
  g.bfs(0);
}
