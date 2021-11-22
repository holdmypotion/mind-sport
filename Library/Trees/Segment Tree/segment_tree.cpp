struct SegTree {
	ll n;
	v64 tree;
	SegTree() = default;
	SegTree(ll n) : n(n) {
		tree.resize(2 * n, 0);
	}

	void insert(ll k, ll x) {
		k += n;
		tree[k] = x;
		for (k /= 2; k >= 1; k /= 2) {
			tree[k] = tree[2 * k] + tree[2 * k + 1];
		}
	}

	ll sum(ll a, ll b) {
		a += n; b += n;
		ll res = 0;
		while (a <= b) {
			if (a % 2 == 1) res += tree[a++];
			if (b % 2 == 0) res += tree[b--];
			a /= 2; b /= 2;
		}
		return res;
	}
};

// solution
void potion() {
	ll n; cin >> n;
	SegTree tree(n);
	forn(i, n) {
		ll x; cin >> x;
		tree.insert(i, x);
	}
	cout << tree.sum(2, 7) << ln;
}