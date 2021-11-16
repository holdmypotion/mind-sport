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
typedef pair<ll, ll> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<ll> v32;
typedef vector<vector<ll> > vv32;
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

ll minCostMatrixMultiplication(v32& d, ll n, v32& p) {
	ll dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));

	auto f = [&](ll i, ll j) {
		return p[j] - p[i - 1];
	};

	for (ll l = 2; l <= n; l++) {  // length of the subarray
		for (ll i = 1; i + l - 1 <= n; i++) {  // start of the subarray
			ll j = i + l - 1;  // end of the subarray
			// base case
			if (l == 2) {
				dp[i][j] = d[i] + d[j];
				continue;
			}

			dp[i][j] = 1e18;
			ll cost = f(i, j);
			for (ll k = i; k < j; k++) {
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

	return dp[1][n];
}

// solution
void potion() {
	ll n; cin >> n;
	v32 d(n + 1), p(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> d[i];
		p[i] = p[i - 1] + d[i];
	}
	cout << minCostMatrixMultiplication(d, n, p) << ln;
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