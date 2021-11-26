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

// solution
void potion() {
	// state: dp[i][j] -> no. of operations to make a string of length j from a string of length i
	// transition: 
	/**
	 * At each step, we have 3 options - consider L and M
	 * 1. remove the element (remove L)
	 * 2. insert a new element (insert M)
	 * 3. modify the existing element (modify L to M)
	 *
	 * Try all the options and take the minimum one!
	 *
	 * 1. if remove: add 1 + operations needed make j with i - 1 string
	 * 2. if insert: add 1 + operations needed to make j - 1 with i string
	 * 3. if modify: add cost(1 if characters don't match, 0 otherwise)
	 * 								+ operations needed to make j - 1 with i - 1 string
	 */

	string s, p, ans, posans; cin >> s >> p;
	int n = s.length(), m = p.length(), count = 0;
	vv32 dp(n + 1, v32(m + 1, INT_MAX));
	dp[0][0] = 0;

	forsn(i, 0, n + 1) {
		forsn(j, 0, m + 1) {
			int cost = (s[i - 1] != p[j - 1]); // returns 1 for mismatch and 0 otherwise
			if (i) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // removing
			}
			if (j) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // inserting
			}
			if (i && j) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost); // modifing
			}
		}
	}
	// for (auto& r : dp) {
	// 	for (auto& ele : r) cout << ele << " ";
	// 	cout << ln;
	// }
	cout << dp[n][m];
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