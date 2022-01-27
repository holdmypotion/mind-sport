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
typedef vector<vector<p32> > vvp32;
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
	ll n; cin >> n;
	string s; cin >> s;
	ll x, y; cin >> x >> y;
	vp64 turncost;

	for (auto ch : s) {
		switch (ch) {
		case 'E':
			turncost.pb({ min(2 * x, 2 * y), 0 });
			break;
		case 'W':
			turncost.pb({ 0, min(2 * x, 2 * y) });
			break;
		case 'N':
			turncost.pb({ min(3 * x, y), min(x, 3 * y) });
			break;
		case 'S':
			turncost.pb({ min(x, 3 * y),  min(3 * x, y) });
			break;
		default:
			break;
		}
	}

	v64 looking_west(n), looking_east(n);

	looking_east[0] = turncost[0].se;
	forsn(i, 1, n) {
		looking_east[i] = looking_east[i - 1] + turncost[i].se;
	}

	looking_west[n - 1] = turncost[n - 1].fi;
	rforsn(i, n - 2, 0) {
		looking_west[i] = looking_west[i + 1] + turncost[i].fi;
	}

	ll bestchoice = min(looking_east[n - 1], looking_west[0]);

	forn(i, n - 1) {
		bestchoice = min(bestchoice, (looking_east[i] + looking_west[i + 1]));
	}

	cout << bestchoice << ln;

}

signed main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t = 1;
	cin >> t;
	while (t--) potion();
	return 0;
} // Alright then, mate!