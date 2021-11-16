/*
 * Sample Input:
5 6
1 5 1
1 4 9
1 2 5
4 5 2
4 3 7
2 3 2
*/

struct graph {
	ll n, m;
	vv64 adj, dis;
	graph() = default;
	graph(ll n) : n(n) {
		adj.resize(n + 1, v64(n + 1));
		dis.resize(n + 1, v64(n + 1));
	};
	graph(ll n, ll m) : n(n), m(m) {
		adj.resize(n + 1, v64(n + 1));
		dis.resize(n + 1, v64(n + 1));
	};

	void init() {
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				if (i == j) dis[i][j] = 0;
				else if (adj[i][j]) dis[i][j] = adj[i][j];
				else dis[i][j] = INF;
			}
		}
	}

	void addEdge(ll u, ll v, ll w) {
		adj[u][v] = w;
		adj[v][u] = w;
	}

	void floydWarshall() {
		init();
		for (ll k = 1; k <= n; k++) {
			for (ll i = 1; i <= n; i++) {
				for (ll j = 1; j <= n; j++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
	}

	void printDis() {
		for (ll i = 1; i <= n; i++) {
			for (ll k = 1; k <= n; k++) {
				cout << dis[i][k] << " ";
			}
			cout << ln;
		}
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
	g.floydWarshall();
	g.printDis();
}