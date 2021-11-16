struct dsu {
	ll n;
	v64 p, size;
	dsu() = default;
	dsu(ll n) : n(n) {
		forn(i, n + 1) {
			p.pb(i);
			size.pb(1);
		}
	}

	bool unite(ll a, ll b) {
		a = find(a);
		b = find(b);
		if (a != b) {
			if (size[a] < size[b]) swap(a, b);
			size[a] += size[b];
			p[b] = a;
			return true;
		}
		return false;
	}

	ll find(ll u) {
		if (p[u] == u) return u;
		// Path compression - Makes successive find runs in O(1);
		return p[u] = find(p[u]);
	}
};
