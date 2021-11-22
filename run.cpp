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
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
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

struct BIT {
	ll n;
	v64 arr, tree;
	BIT() = default;
	BIT(ll n) : n(n) {
		arr.resize(n + 1);
		tree.resize(n + 1, 0);
	}

	void add(ll k, ll x) {
		// adding the element to the array
		arr[k] += x;

		// adding the element to binary indexed tree
		while (k <= n) {
			tree[k] += x;
			k += (k & -k);
		}
	}

	ll prefix_sum(ll k) {
		ll res = 0;
		while (k >= 1) {
			res += tree[k];
			k -= (k & -k);
		}
		return res;
	}

	ll sum(ll i, ll j) {
		return prefix_sum(j) - prefix_sum(i - 1);
	}
};

// solution
void potion() {
	ll n; cin >> n;
	BIT tree(n);
	forsn(i, 1, n + 1) {
		ll x; cin >> x;
		tree.add(i, x);
	}
	cout << tree.sum(3, 4) << ln;
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