struct graph {
	ll n, m;
	vector<tuple<ll, ll, ll>> edges;
	v64 dis;
	graph() = default;
	graph(ll n, ll m) : n(n), m(m) {
		dis.resize(n + 1, INF);
	};

	void addEdge(ll u, ll v, ll w) {
		edges.pb({ u, v, w });
	}

	bool shortestPath(ll s) {
		dis[s] = 0;
		par[s] = 0;
		ll till;
		forn(i, n) {
			till = 0;
			for (auto& [u, v, w] : edges) {
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					par[v] = u;
					till = v;
				}
			}
		}

		if (till) {
			//! To Print negative cycle.
			// v64 cycle;
			// forn(i, n) till = par[till];
			// ll node;
			// for (int node = till;; node = par[node]) {
			// 	cycle.pb(node);
			// 	if (node == till && cycle.size() > 1) break;
			// }

			// reverse(all(cycle));
			// for (auto& ele : cycle) cout << ele << " ";
		}
		else return false;

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
		forsn(i, 1, n + 1) {
			cout << i << ": " << dis[i];
		}
	}
}