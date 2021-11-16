
// * TC = O(n + mlog(m))
// ? Reason:
// * Every node is processed only once due to the processed array check -> O(n)
// * Every edge is traversed only once and at each edge we add an element pair 
// *    to the priority queue - O(mlog(m)
// * 		Total edges -> m
// * 		Adding an element to a priority queue -> O(log(n));

// ! Note: The priority queue can have multiple occurrences of the same node
// ! 			 with different distances(priorities).
// !       The ones with highest priority will be selected
// ! 			 
// !       Note that the priority queue contains negative distances to nodes. The reason
// !       for this is that the default version of the C++ priority queue finds maximum
// !       elements, while we want to find minimum elements. By using negative distances,
// !       we can directly use the default priority queue

const ll mxn = 1000;

struct graph {
	ll n, m;
	vp64 adj[mxn];
	vector<bool> processed;
	v64 dis;
	priority_queue<pair<ll, ll>> q;
	graph() = default;
	graph(ll n) : n(n) {
		processed.resize(n + 1, false);
		dis.resize(n + 1, INF);
	};
	graph(ll n, ll m) : n(n), m(m) {
		processed.resize(n + 1, false);
		dis.resize(n + 1, INF);
	};

	void addEdge(ll u, ll v, ll w) {
		adj[u].pb({ v, w });
		adj[v].pb({ u, w });
	}

	void dikjstra(ll s) {
		dis[s] = 0;
		q.push({ 0, s });
		while (!q.empty()) {
			ll a = q.top().second; q.pop();
			if (processed[a]) continue;
			processed[a] = true;

			for (auto& v : adj[a]) {
				ll b = v.first, w = v.second;
				dis[b] = min(dis[b], dis[a] + w);
				q.push({ -dis[b], b });
			}
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
	g.dikjstra(1);

	for (auto& u : g.dis) {
		if (u != INF) cout << u << " ";
	}
}