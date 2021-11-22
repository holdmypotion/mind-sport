bool is_subset(v64& arr, ll n, ll k) {
	// dp[ending index][sum]
	vvb dp(n + 1, vb(k + 1, false));

	// Marking all the true for 0 sum
	forn(i, n + 1) dp[i][0] = true;

	forsn(i, 1, n + 1) {
		forsn(j, 1, k + 1) {
			if (j < arr[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i]];
		}
	}

	return dp[n][k];
}

// solution
void potion() {
	ll n, target; cin >> n;
	v64 arr(n + 1);
	forsn(i, 1, n + 1) {
		cin >> arr[i];
	}
	cin >> target;
	cout << is_subset(arr, n, target);
}