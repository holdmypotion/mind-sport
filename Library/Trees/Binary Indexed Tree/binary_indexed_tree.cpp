struct BIT {
	ll n;
	v64 arr, tree;
	BIT() = default;
	BIT(ll n) : n(n) {
		arr.resize(n + 1);
		tree.resize(n + 1, 0);
	}

	void add(ll k, ll x) {
		// adding the element to the array
		arr[k] += x;

		// adding the element to binary indexed tree
		while (k <= n) {
			tree[k] += x;
			k += (k & -k);
		}
	}

	ll prefix_sum(ll k) {
		ll res = 0;
		while (k >= 1) {
			res += tree[k];
			k -= (k & -k);
		}
		return res;
	}

	ll sum(ll i, ll j) {
		return prefix_sum(j) - prefix_sum(i - 1);
	}
};

// solution
void potion() {
	ll n; cin >> n;
	BIT tree(n);
	forsn(i, 1, n + 1) {
		ll x; cin >> x;
		tree.add(i, x);
	}
	cout << tree.sum(3, 4) << ln;
}
