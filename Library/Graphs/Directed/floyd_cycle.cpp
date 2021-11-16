struct graph {
	ll n, m;
	vv64 adj;
	graph() = default;
	graph(ll n) : n(n) {
		adj.resize(n + 1);
	};
	graph(ll n, ll m) : n(n), m(m) {
		adj.resize(n + 1);
	};

	void addEdge(ll u, ll v) {
		adj[u].pb(v);
	}

	ll succ(ll x) {
		if (!adj[x].empty()) return adj[x][0];
		return -1;
	}

	ll cycleLength(ll x) {
		ll a = succ(x), b = succ(succ(x)), count = 1;
		while (a != b) {
			a = succ(a);
			b = succ(succ(b));
			if (a == -1 || b == -1) return 0;
		}

		// Getting the first node
		a = x;
		while (a != b) {
			a = succ(a);
			b = succ(b);
		}

		// Counting cycle
		b = succ(a);
		while (a != b) {
			b = succ(b);
			count++;
		}

		return count;
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
	cout << g.cycleLength(1);

}
