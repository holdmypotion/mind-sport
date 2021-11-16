constexpr ll mxn = 1000;

struct graph {
	ll n, m;
	v64 adj[mxn];
	v64 dis, color;
	vector<bool> vis;
	queue<ll> q;
	graph() = default;
	graph(ll n) : n(n) {
		vis.resize(n + 1, false);
		dis.resize(n + 1);
		color.resize(n + 1, -1);
	};
	graph(ll n, ll m) : n(n), m(m) {
		vis.resize(n + 1, false);
		dis.resize(n + 1);
		color.resize(n + 1, -1);
	};

	void addEdge(ll a, ll b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool bfs(ll u) {
		vis[u] = true;
		dis[u] = 0;
		q.push(u);
		while (!q.empty()) {
			auto s = q.front(); q.pop();
			if (color[s] == -1) color[u] = 1;
			for (auto v : adj[s]) {
				if (color[v] == color[s]) return false;
				if (vis[v]) continue;
				vis[v] = true;
				dis[v] = dis[s] + 1;
				color[v] = 1 - color[s];
				q.push(v);
			}
		}
		return true;
	}

	bool isBipartite() {
		forn(i, n) {
			if (!bfs(i)) return false;
		}
		return true;
	}

};