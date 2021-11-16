#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
/**
 * * Min Cost matrix multiplication
 * ? State of the DP:
 * * dp[l][r] = min scalar multiplication needed to multiply the matrix
 * * 						chain l...r
 * ? Transition Operation:
 * * dp[i][j] = min(d[i][j], dp[i][k] + dp[k+1][j] + cost)
 * * here cost = row[i] * row[k] * col[j] or row[i] * col[k+1] * col[j]
 *
 * ! Remember: An input of 7 numbers will form 6 matrices
 * ! 					 The solution uses 1-based indexing for dp.
 */
 // * n-1 matrices out of n elements
 // A[1] = d[0] x d[1]
 // A[2] = d[1] x d[2]
 // ...
 // A[n-1] = d[n] X d[n-1]

ll minCostMatrixMultiplication(v32& d, int n) {
	int dp[n][n];
	memset(dp, 0, sizeof(dp));

	// * l will go upto n-1 as there are n-1 matrices in total.
	for (int l = 2; l < n; l++) {  // length of the subarray
		for (int i = 1; i + l - 1 < n; i++) {  // start of the subarray
			int j = i + l - 1;  // end of the subarray
			// base case
			if (l == 2) {
				dp[i][j] = d[i - 1] * d[i] * d[j];
				continue;
			}

			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				int cost = d[i - 1] * d[k] * d[j];
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost);
			}
		}
	}

	// for (auto& u : dp) {
	// 	for (auto& v : u) {
	// 		cout << v << " ";
	// 	}
	// 	cout << "\n";
	// }

	// * Ans at (1, n-1) -> starting index = 1, ending index = n - 1
	// * as there are n-1 matrices! [AxB, BxC, ..., PxQ]
	// *                              1    2   ...  n-1
	return dp[1][n - 1];
}

// solution
void potion() {
	int n; cin >> n;
	v32 d(n);
	for (auto& it : d) cin >> it;
	cout << "Minimum Cost Matrix multiplication: " << minCostMatrixMultiplication(d, n);
}

signed main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t = 1;
	// cin >> t;
	while (t--) potion();
	return 0;
} // Alright then, mate