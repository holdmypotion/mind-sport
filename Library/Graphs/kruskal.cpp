struct dsu {
  ll n;
  v64 p, size;
  dsu() = default;
  dsu(ll n) : n(n) {
    forn(i, n + 1) {
      p.pb(i);
      size.pb(1);
    }
  }

  bool unite(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      size[a] += size[b];
      p[b] = a;
      return true;
    }
    return false;
  }

  ll find(ll u) {
    if (p[u] == u) return u;
    // Path compression - Makes successive find runs in O(1);
    return p[u] = find(p[u]);
  }
};

struct graph {
  ll n, m;
  vt64 edges, mst;
  graph() = default;
  graph(ll n) : n(n) {}
  graph(ll n, ll m) : n(n), m(m) {}

  void addEdge(ll u, ll v, ll w) {
    edges.pb({ u, v, w });
  }

  ll kruskal() {
    dsu s(n);
    sort(edges.begin(), edges.end(), [&](t64& t1, t64& t2) {
      auto [a, b, c] = t1;
      auto [x, y, z] = t2;
      return c < z;
    });

    ll cost = 0;
    for (auto& [u, v, w] : edges) {
      if (s.unite(u, v)) {
        mst.pb({ u, v, w });
        cost += w;
      }
    }

    // * print mst
    // for (auto& u : mst) {
    // 	for (auto& v : u) cout << v << " ";
    // 	cout << ln;
    // }
    return cost;
  }
};

// solution
void potion() {
  ll n, m; cin >> n >> m;
  graph g(n, m);
  forn(i, m) {
    ll u, v, w; cin >> u >> v >> w;
    g.addEdge(u, v, w);
  }
  cout << g.kruskal();
}
