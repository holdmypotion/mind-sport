struct graph {
	ll n, m;
	vv64 adj, dp;
	vb vis;
	graph() = default;
	graph(ll n) : n(n) {
		adj.resize(n + 1);
		dp.resize(n + 1, v64(18));
		vis.resize(n + 1);
	}

	graph(ll n, ll m) : n(n), m(m) {
		adj.resize(n + 1);
		dp.resize(n + 1, v64(18));
		vis.resize(n + 1);
	}

	void addEdge(ll u, ll v) {
		adj[u].pb(v);
	}

	void dfs(ll u, ll p) {
		dp[u][0] = p;
		for (int i = 1; i <= 18; i++) {
			dp[u][i] = dp[dp[u][i - 1]][i - 1];
		}
		for (auto& v : adj[u]) {
			if (v != p) dfs(v, u);
		}
	}

	ll ancestor(ll u, ll k) {
		for (ll i = 20; ~i; i--) {
			if ((1 << i) <= k) {
				u = dp[u][i];
				k -= (1 << i);
			}
		}

		return (u == 0 ? -1 : u);
	}
};

// solution
void potion() {
	ll n, m; cin >> n >> m;
	graph g(n, m);
	forn(i, m) {
		ll u, v; cin >> u >> v;
		g.addEdge(u, v);
		g.addEdge(v, u);
	}
	g.dfs(1, 0);

	ll u, k; cin >> u >> k;
	cout << g.ancestor(u, k);
}
