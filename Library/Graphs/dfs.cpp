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
		cout << u << " -> ";
		for (auto& v : adj[u]) {
			if (!vis[v]) dfs(v);
		}
	}
};

void potion() {
	ll n, m; cin >> n >> m;
	graph g(n, m);

	forn(i, m) {
		ll u, v; cin >> u >> v;
		g.addEdge(u, v);
		g.addEdge(v, u);
	}

	g.dfs(1);
}
