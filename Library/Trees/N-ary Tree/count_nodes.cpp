/*
* Sample Input:
8 7
1 2
1 3
1 4
2 5
2 6
6 8
4 7
*/

struct graph {
	ll n, m;
	vv64 adj;
	v64 count;
	graph() = default;
	graph(ll n) : n(n) {
		adj.resize(n + 1);
		count.resize(n + 1);
	};
	graph(ll n, ll m) : n(n), m(m) {
		adj.resize(n + 1);
		count.resize(n + 1);
	};

	void addEdge(ll u, ll v) {
		adj[u].pb(v);
		adj[v].pb(u);
	}

	void dfs(ll u, ll p) {
		count[u] = 1;
		for (auto& v : adj[u]) {
			if (v == p) continue;
			dfs(v, u);
			count[u] += count[v];
		}
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
	g.dfs(1, 0);

	forsn(i, 1, n + 1) {
		cout << i << ": " << g.count[i] << ln;
	}
}
