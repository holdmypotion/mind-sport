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

int minimum_coins(v32& coins, int n, int x) {
	v64 dp(x + 1, INF);
	dp[0] = 0;
	/**
	 * 0-> 0
	 * 1-> 1
	 * 2-> 2
	 * 3 -> 3
	 * 4 -> 4
	 * 5 -> 1
	 * ..
	 * 11 -> 33
	 */
	forn(i, x + 1) {
		// coins -> [1 5 7]
		for (int j = 0; j < n; j++) {
			if (i >= coins[j]) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return (dp[x] == INF ? -1 : dp[x]);
}

// solution
void potion() {
	// state -> dp[i] -> min num of coins required to make i
	// transition -> dp[i] = min(dp[i], dp[i - coins[j]] + 1)

	int n, x; cin >> n >> x;
	v32 coins(n);
	forn(i, n) {
		cin >> coins[i];
	}

	cout << minimum_coins(coins, n, x);
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