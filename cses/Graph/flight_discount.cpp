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

/**
 * ! Single dikjstra doesn't work
 * Look at this example
 * Sample input:
		4 4
		1 2 100
		2 4 100
		1 3 10
		3 4 200
 */

struct graph {
	ll n, m;
	vt64 edges;
	vvp64 adj, radj;
	vector<bool> vis;
	v64 dis1, dis2;
	graph() = default;
	graph(ll n) : n(n) {
		adj.resize(n + 1);
		radj.resize(n + 1);
	};

	graph(ll n, ll m) : n(n), m(m) {
		adj.resize(n + 1);
		radj.resize(n + 1);
	};

	void addEdge(ll u, ll v, ll w) {
		adj[u].pb({ v, w });
		radj[v].pb({ u, w });
		edges.pb({ u, v, w });
	}

	void dikjstra(ll s, v64& dis, vvp64& adj) {
		priority_queue<pair<ll, ll>> q;
		vis.assign(n + 1, false);
		dis.assign(n + 1, INF);
		dis[s] = 0;
		q.push({ 0, s });
		while (!q.empty()) {
			ll a = q.top().se; q.pop();
			if (vis[a]) continue;
			vis[a] = true;
			for (auto& v : adj[a]) {
				ll b = v.first, w = v.second;
				if (dis[b] > dis[a] + w) {
					dis[b] = dis[a] + w;
					q.push({ -dis[b], b });
				}
			}
		}
	}
	void shortest_route() {
		dikjstra(1, dis1, adj);
		dikjstra(n, dis2, radj);
		ll minRoute = INF;

		// * We are meeting in the middle
		// dis1[u] -> distance from 1 to node u
		// dis2[v] -> distance from n to node v
		// w -> weight of the edge between u and v
		// * This loop goes through all the edges, trying the discount coupon.
		// * dis1 and dis2 inevitably contain the shortest distances.
		// ? (1)...shortest dis...(u)---w/2---(v)...shortest dis...(n)
		for (auto& [u, v, w] : edges) {
			minRoute = min(minRoute, dis1[u] + dis2[v] + w / 2);
		}
		cout << minRoute;
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
	g.shortest_route();
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