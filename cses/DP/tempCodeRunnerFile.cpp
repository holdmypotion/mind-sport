	// forsn(i, 1, a + 1) {
	// 	forsn(j, 1, b + 1) {
	// 		if (i == j) dp[i][j] = 0;
	// 		else if (i > j) dp[i][j] = dp[j][i];
	// 		else dp[i][j] = dp[i][j - i] + 1;
	// 	}
	// }
	// for (auto& r : dp) {
	// 	for (auto& ele : r) cout << ele;
	// 	cout << ln;
	// }
	// cout << dp[a][b];