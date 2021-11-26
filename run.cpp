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
typedef vector<int> v32;
typedef vector<ll> v64;
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

struct graph {
	ll n, m, timer;
	vv64 adj, dp;
	v64 in, out;
	vb vis;
	graph() = default;
	graph(ll n) : n(n) {
		timer = 0;
		adj.resize(n + 1);
		dp.resize(n + 1, v64(18));
		vis.resize(n + 1);
		in.resize(n + 1);
		out.resize(n + 1);
	}

	graph(ll n, ll m) : n(n), m(m) {
		timer = 0;
		adj.resize(n + 1);
		dp.resize(n + 1, v64(18));
		vis.resize(n + 1);
		in.resize(n + 1);
		out.resize(n + 1);
	}

	void addEdge(ll u, ll v) {
		adj[u].pb(v);
	}

	void dfs(ll u, ll p) {
		dp[u][0] = p;
		in[u] = timer++;
		for (int i = 1; i <= 18; i++) {
			dp[u][i] = dp[dp[u][i - 1]][i - 1];
		}
		for (auto& v : adj[u]) {
			if (v != p) dfs(v, u);
		}
		out[u] = timer++;
	}

	bool is_ancestor(ll u, ll v) {
		// u is_ancestor of v;
		return in[u] <= in[v] and out[u] >= out[v];
	}

	ll lca(ll u, ll v) {
		if (is_ancestor(u, v)) return u;
		if (is_ancestor(v, u)) return v;
		for (ll i = 18; ~i; i--) {
			cout << ~i << ln;
			if (!is_ancestor(dp[u][i], v)) {
				u = dp[u][i];
			}
		}
		// u = not is_ancestor of v;
		return dp[u][0]; // parent of u is lca
	}
};

// solution
void potion() {
	ll n, q; cin >> n >> q;
	graph g(n);
	forsn(i, 2, n + 1) {
		// we are getting parents for each node
		ll p; cin >> p;
		g.addEdge(i, p);
		g.addEdge(p, i);
	}
	g.dfs(1, 1);

	while (q--) {
		ll u, k; cin >> u >> k;
		cout << g.lca(u, k) << ln;
	}
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