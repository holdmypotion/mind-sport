enum Color { WHITE, GRAY, BLACK };

constexpr ll mxn = 1000;

struct graph {
  ll n, m;
  v64 adj[mxn];
  v64 color;
  graph() = default;
  graph(ll n) : n(n) {
    color.resize(n + 1, WHITE);
  };
  graph(ll n, ll m) : n(n), m(m) {
    color.resize(n + 1, WHITE);
  };

  void addEdge(ll a, ll b) {
    adj[a].push_back(b);
    adj[a].push_back(b);
  }

  bool dfs(ll u) {
    color[u] = GRAY;

    for (auto& v : adj[u]) {
      if (color[v] == GRAY || (color[v] == WHITE && dfs(v))) return true;
    }
    color[u] = BLACK;
    return false;
  }

  bool isCyclic() {
    forn(i, n) {
      if (color[i] == WHITE) {
        if (dfs(i)) return true;
      }
    }
    return false;
  }
};
