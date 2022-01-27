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

struct graph {
	ll n, m;
	vector<tuple<ll, ll, ll>> edges;
	v64 dis, par;
	graph() = default;
	graph(ll n) : n(n) {
		dis.resize(n + 1, INF);
		par.resize(n + 1, -1);
	};
	graph(ll n, ll m) : n(n), m(m) {
		dis.resize(n + 1, INF);
		par.resize(n + 1, -1);
	};

	void addEdge(ll u, ll v, ll w) {
		edges.pb({ u, v, w });
	}

	bool containsNegativeCycle(ll s) {
		dis[s] = 0;
		par[s] = 0;
		ll till;
		forn(i, n) {
			till = 0;
			for (auto& [u, v, w] : edges) {
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					par[v] = u;
					till = v;
				}
			}
		}

		if (till) {
			cout << "YES" << ln;
			v64 cycle;
			forn(i, n) till = par[till];
			ll node;
			for (int node = till;; node = par[node]) {
				cycle.pb(node);
				if (node == till && cycle.size() > 1) break;
			}

			reverse(all(cycle));
			for (auto& ele : cycle) cout << ele << " ";
		}
		else {
			cout << "NO";
			return false;
		}
		return true;
	}

};

// solution
void potion() {
	ll n, m; cin >> n >> m;
	graph g(n, m);
	forn(i, m) {
		ll u, v, w; cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}

	g.containsNegativeCycle(1);
}

signed main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("test_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t = 1;
	// cin >> t;
	while (t--) potion();
	return 0;
} // Alright then, mate!