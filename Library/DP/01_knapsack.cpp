ll max_knapsack(v64& wt, v64& val, ll n, ll k) {
	// dp[ending index of weights][sum]
	vv64 dp(n + 1, v64(k, 0));

	forsn(i, 1, n + 1) {
		forsn(j, 1, k + 1) {
			if (j < wt[i]) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], val[i] + dp[i - 1][j - wt[i]]);
			}
		}
	}

	return dp[n][k];
}

// solution
void potion() {
	ll n, target; cin >> n;
	v64 wt(n + 1), val(n + 1);
	forsn(i, 1, n + 1) cin >> wt[i];
	forsn(i, 1, n + 1) cin >> val[i];
	cin >> target;

	cout << max_knapsack(wt, val, n, target);
}