// author: holdmypotion
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
typedef tuple<ll, ll, ll> t64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<bool> vb;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<vector<bool>> vvb;
typedef vector<p64> vp64;
typedef vector<t64> vt64;
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
constexpr int mod = 1e9 + 7;

int max_arrays(int n, int m) {
	vv32 dp(n, v32(m + 1, 0));
	int first; cin >> first;
	if (first == 0) {
		fill(all(dp[0]), 1);
	}
	else {
		dp[0][first] = 1;
	}

	for (int i = 1; i < n; i++) {
		int ele; cin >> ele;
		if (ele == 0) {  // ith element can be anything. Check all the possibilities
			for (int j = 1; j <= m; j++) {
				for (int k : {j - 1, j, j + 1}) {
					if (k >= 1 && k <= m) {
						(dp[i][j] += dp[i - 1][k]) %= mod;
					}
				}
			}
		}
		else {  // ith element is `ele`. Check in the vicinity of `ele`
			for (int k : {ele - 1, ele, ele + 1}) {
				if (k >= 1 && k <= m) {
					(dp[i][ele] += dp[i - 1][k]) %= mod;
				}
			}
		}
	}

	int ans = 0;
	// Get all the valid arrays of size n, i.e. ending at index `n-1`
	for (int j = 1; j <= m; j++) (ans += dp[n - 1][j]) %= mod;
	return ans;
}

// solution
void potion() {
	// state: dp[i][x] -> max no. of arrays till index i with last element x, i.e input[i] = x;
	// transition: dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
	int n, m; cin >> n >> m;
	cout << max_arrays(n, m);
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
} // Alright then, mate!