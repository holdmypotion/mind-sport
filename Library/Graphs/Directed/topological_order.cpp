enum Color { WHITE, GRAY, BLACK };

struct graph {
  ll n, m;
  vv64 adj;
  v64 color, topOrder;
  graph() = default;
  graph(ll n) : n(n) {
    adj.resize(n + 1);
    color.resize(n + 1, WHITE);
  };
  graph(ll n, ll m) : n(n), m(m) {
    adj.resize(n + 1);
    color.resize(n + 1, WHITE);
  };

  void addEdge(ll u, ll v) {
    adj[u].push_back(v);
  }

  bool dfs(ll u) {
    color[u] = GRAY;

    for (auto& v : adj[u]) {
      if (color[v] == GRAY) return false;
      if (color[v] == WHITE) dfs(v);
    }
    topOrder.pb(u);
    color[u] = BLACK;
    return true;
  }

  void topologicalOrder() {
    forsn(i, 1, n + 1) {
      if (color[i] == WHITE) {
        if (!dfs(i)) {
          cout << "Graph contains a cycle!";
          return;
        }
      }
    }
    rforn(i, topOrder.size() - 1) cout << topOrder[i] << " ";
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

  g.topologicalOrder();
}
