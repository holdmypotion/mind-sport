1 << n);

	// dp[0] = { 1, 0 };
	// for (int s = 1; s < (1 << n); s++) { // go through all the subsets
	// 	dp[s] = { n + 1, 0 } // initial rides = n+1
	// 	for (int p = 0; p < n; p++) {
	// 		if (s & (1 << p)) {
	// 			auto option = dp[s ^ (1 << p)];
	// 			if (option.second + wt[p] <= x) {
	// 				// add p to an existing ride
	// 				option.second += wt[p];
	// 			}
	// 			else {
	// 				// reserve a new ride for p
	// 				option.first++;
	// 				option.second = wt[p];
	// 			}
	// 			dp[s] = min(dp[s], option);
	// 		}
	// 	}
	// }

	// cout << dp[(1 << n)];