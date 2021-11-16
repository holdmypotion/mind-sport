struct graph {
	ll n, m;
	vector<tuple<ll, ll, ll>> edges;
	v64 dis;
	graph() = default;
	graph(ll n) : n(n) {
		dis.resize(n + 1, INF);
	};
	graph(ll n, ll m) : n(n), m(m) {
		dis.resize(n + 1, INF);
	};

	void addEdge(ll u, ll v, ll w) {
		edges.pb({ u, v, w });
	}

	bool shortestPath(ll s) {
		dis[s] = 0;
		forn(i, n) {
			for (auto& [u, v, w] : edges) {
				dis[v] = min(dis[v], dis[u] + w);
			}
		}

		for (auto& [u, v, w] : edges) {
			if (dis[u] != INF && dis[u] + w < dis[v]) {
				cout << "Graph contains -ve cycle";
				return false;
			}
		}

		return true;
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

	if (g.shortestPath(1)) {

		for (auto& u : g.dis) {
			if (u != INF) cout << u << " ";
		}
	}
}