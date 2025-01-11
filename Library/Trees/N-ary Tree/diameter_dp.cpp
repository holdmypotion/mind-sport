
/*
* Sample Input:
8 7
1 2
1 3
1 4
2 5
2 6
4 7
6 8
*/

struct graph {
  ll n, m, dia = 0;
  vv64 adj, dp;
  graph() = default;
  graph(ll n) : n(n) {
    dp.resize(2, v64(n + 1, 0));
    adj.resize(n + 1);
  };
  graph(ll n, ll m) : n(n), m(m) {
    adj.resize(n + 1);
    dp.resize(2, v64(n + 1, 0));
  };

  void addEdge(ll u, ll v) {
    adj[u].pb(v);
    adj[v].pb(u);
  }

  ll dfs(ll u, ll p) {
    ll f = -1, s = -1;
    for (auto& v : adj[u]) {
      if (v == p) continue;
      dfs(v, u);
      if (f == -1) f = dp[0][v];
      else if (f <= dp[0][v]) {
        s = f;
        f = dp[0][v];
      }
      else if (dp[0][v] > s) s = dp[0][v];
    }

    if (s != -1) dp[1][u] = 2 + f + s; // Dia passing from that node
    if (f != -1) dp[0][u] += f + 1; // Height of node

    return max(dp[0][u], dp[1][u]);
  }

  ll diameter(ll u) {
    return dfs(u, 0);
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
  cout << g.diameter(1) << ln;
  cout << ln;
  for (auto& ele : g.dp) {
    for (auto& it : ele) {
      cout << it << " ";
    }
    cout << ln;
  }
}
