/*
* Sample Input:
8 7
1 2
1 3
1 4
2 5
2 6
4 7
*/

struct graph {
  ll n, m;
  vv64 adj;
  v64 dp;
  graph() = default;
  graph(ll n) : n(n) {
    dp.resize(n + 1, -1);
    adj.resize(n + 1);
  };
  graph(ll n, ll m) : n(n), m(m) {
    adj.resize(n + 1);
    dp.resize(n + 1, -1);
  };

  void addEdge(ll u, ll v) {
    adj[u].pb(v);
    adj[v].pb(u);
  }

  ll dfs(ll u, ll p) {
    for (auto& v : adj[u]) {
      if (v == p) continue;
      dp[v] = max(dp[v], dfs(v, u));
      dp[u] = max(dp[u], dp[v]);
    }
    dp[u] += 1;
    return dp[u];
  }

  ll height(ll u) {
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
  cout << g.height(2);

  for (auto& it : g.dp) cout << it << " ";
}
