constexpr ll mxn = 1000;

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
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	void dfs(ll u) {
		vis[u] = true;
		for (auto& v : adj[u]) {
			if (!vis[v]) dfs(v);
		}
	}

	ll countConnectedComponents() {
		ll count = 0;
		forn(i, n) {
			if (!vis[i]) {
				count++;
				dfs(i);
			}
		}
		return count;
	}

};

// solution
void potion() {
	ll n, m; cin >> n >> m;
	graph g(n, m);
	forn(i, m) {
		int a, b; cin >> a >> b;
		g.addEdge(a, b);
	}
	// g.dfs(0);
	cout << g.countConnectedComponents();
}