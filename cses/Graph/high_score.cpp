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
	v64 dis;
	vv64 adj1, adj2;
	vb vis1, vis2;
	graph() = default;
	graph(ll n) : n(n) {
		adj1.resize(n + 1);
		vis1.resize(n + 1, false);
		adj2.resize(n + 1);
		vis2.resize(n + 1, false);
		dis.resize(n + 1, -INF);
	};
	graph(ll n, ll m) : n(n), m(m) {
		adj1.resize(n + 1);
		vis1.resize(n + 1, false);
		adj2.resize(n + 1);
		vis2.resize(n + 1, false);
		dis.resize(n + 1, -INF);
	};

	void addEdge(ll u, ll v, ll w) {
		edges.pb({ u, v, w });
		adj1[u].pb(v); // adjacency list
		adj2[v].pb(u); // reverse adjacency list
	}

	// dfs on adj1
	void dfs1(ll u) {
		vis1[u] = true;
		for (auto& v : adj1[u]) {
			if (!vis1[v]) dfs1(v);
		}
	}

	// dfs on adj2 (reverse adj)
	void dfs2(ll u) {
		vis2[u] = true;
		for (auto& v : adj2[u]) {
			if (!vis2[v]) dfs2(v);
		}
	}

	void pathWithMaxScore(ll s) {
		dfs1(s); dfs2(n);
		dis[s] = 0;
		forn(i, n) {
			for (auto& [u, v, w] : edges) {
				if (dis[v] < dis[u] + w) {
					dis[v] = dis[u] + w;
					// last round but still increase in dis -> +ve sum cycle
					// && vis1[v] && vis2[v] == true -> there exists a path like 1..v..n
					if (i == n - 1 && vis1[v] && vis2[v]) { cout << -1; return; }
				}
			}
		}
		cout << dis[n];

	}

};

// solution
void potion() {
	// ? Solution
	/**
	 * Run dfs1 from source and dfs2 from destination.
	 * mark vis1 for dfs1 and vis2 for dfs2
	 * if there exists a +ve sum cycle (can be easily found in bellman-ford)
	 * and the vis1 && vis2 is true for that node. We have infinite as the ans hence, print -1
	 * otherwise print dis[n];
	 */
	ll n, m; cin >> n >> m;
	graph g(n, m);
	forn(i, m) {
		ll u, v, w; cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	g.pathWithMaxScore(1);
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