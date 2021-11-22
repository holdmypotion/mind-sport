ll minCost(v64& h, ll n) {
	v64 dp(n, 0);
	forsn(i, 1, n) {
		if (i == 1) dp[i] = abs(h[i] - h[i - 1]);
		else {
			ll jump1 = abs(h[i] - h[i - 1]) + dp[i - 1];
			ll jump2 = abs(h[i] - h[i - 2]) + dp[i - 2];
			dp[i] = min(jump1, jump2);
		}
		// cout << h[i] << ": " << dp[i] << ln;
	}
	return dp[n - 1];
}

// solution
void potion() {
	ll n; cin >> n;
	v64 h;
	forn(i, n) {
		ll x; cin >> x;
		h.pb(x);
	}
	cout << minCost(h, n);
}
