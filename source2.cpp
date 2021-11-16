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

// ! Caution: 
/**
 * ! if you reverse the graph after the first dfs you have to process the nodes
 * ! in reverse order and hence use a stack
 * * In this implimentation, a queue is used and hence there is no need to
 * * reverse the graph.
 */

struct graph {
	ll n, m;
	vv64 adj;
	v64 dfsArr;
	vector<bool> vis;
	graph() = default;
	graph(ll n) : n(n) {
		adj.resize(n + 1);
		vis.resize(n + 1);
	};
	graph(ll n, ll m) : n(n), m(m) {
		adj.resize(n + 1);
		vis.resize(n + 1);
	};

	void addEdge(ll u, ll v) {
		adj[u].pb(v);
	}

	void dfs(ll u) {
		vis[u] = true;
		// cout << u << " ";
		dfsArr.pb(u);
		for (auto& v : adj[u]) {
			if (!vis[v]) dfs(v);
		}
	}
};

// solution
void potion() {
	ll n, m; cin >> n >> m;
	graph g(n, m);
	forn(i, m) {
		ll u, v; cin >> u >> v;
		g.addEdge(u, v);
		g.addEdge(v, u);
	}
	g.dfs(1);
	for (auto& ele : g.dfsArr) cout << ele << " ";
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