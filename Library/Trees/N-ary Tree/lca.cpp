struct graph {
	ll n, m, timer;
	vv64 adj, dp;
	v64 in, out;
	vb vis;
	graph() = default;
	graph(ll n) : n(n) {
		timer = 0;
		adj.resize(n + 1);
		dp.resize(n + 1, v64(18));
		vis.resize(n + 1);
		in.resize(n + 1);
		out.resize(n + 1);
	}

	graph(ll n, ll m) : n(n), m(m) {
		timer = 0;
		adj.resize(n + 1);
		dp.resize(n + 1, v64(18));
		vis.resize(n + 1);
		in.resize(n + 1);
		out.resize(n + 1);
	}

	void addEdge(ll u, ll v) {
		adj[u].pb(v);
	}

	void dfs(ll u, ll p) {
		dp[u][0] = p;
		in[u] = timer++;
		for (int i = 1; i <= 18; i++) {
			dp[u][i] = dp[dp[u][i - 1]][i - 1];
		}
		for (auto& v : adj[u]) {
			if (v != p) dfs(v, u);
		}
		out[u] = timer++;
	}

	bool is_ancestor(ll u, ll v) {
		// u is_ancestor of v;
		return in[u] <= in[v] and out[u] >= out[v];
	}

	ll lca(ll u, ll v) {
		if (is_ancestor(u, v)) return u;
		if (is_ancestor(v, u)) return v;
		for (ll i = 18; ~i; i--) {
			cout << ~i << ln;
			if (!is_ancestor(dp[u][i], v)) {
				u = dp[u][i];
			}
		}
		// u = not is_ancestor of v;
		return dp[u][0]; // parent of u is lca
	}
};

// solution
void potion() {
	ll n, q; cin >> n >> q;
	graph g(n);
	forsn(i, 2, n + 1) {
		// we are getting parents for each node
		ll p; cin >> p;
		g.addEdge(i, p);
		g.addEdge(p, i);
	}
	g.dfs(1, 1);

	while (q--) {
		ll u, k; cin >> u >> k;
		cout << g.lca(u, k) << ln;
	}
}

