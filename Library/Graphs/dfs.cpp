const ll mxn = 1000;

struct graph {
	ll n, m;
	v64 adj[mxn];
	vector<bool> vis;
	graph() = default;
	graph(ll n) : n(n) {
		vis.resize(n + 1, false);
	};
	graph(ll n, ll m) : n(n), m(m) {
		vis.resize(n + 1, false);
	};

	void addEdge(ll a, ll b) {
		adj[a].pb(b);
		adj[b].pb(a);
	}

	void dfs(ll u) {
		vis[u] = true;
		cout << u << " -> ";
		for (auto& v : adj[u]) {
			if (!vis[v]) dfs(v);
		}
	}
};
