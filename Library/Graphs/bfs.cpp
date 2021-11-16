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
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
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

constexpr ll mxn = 1000;

struct graph {
	ll n, m;
	v64 adj[max_element];
	vector<bool> vis, dis;
	queue<ll> q;
	graph() = default;
	graph(ll n) : n(n) {
		vis.resize(n + 1, false);
		dis.resize(n + 1, false);
	};
	graph(ll n, ll m) : n(n), m(m) {
		vis.resize(n + 1, false);
		dis.resize(n + 1, false);
	};

	void addEdge(ll a, ll b) {
		adj[a].push_back(b);
	}

	void bfs(ll u) {
		vis[u] = true;
		dis[u] = 0;
		q.push(u);
		while (!q.empty()) {
			auto s = q.front(); q.pop();
			cout << s << " ";
			for (auto v : adj[s]) {
				if (vis[v]) continue;
				vis[v] = true;
				dis[v] = dis[s] + 1;
				q.push(v);
			}
		}
	}
};

// solution
void potion() {
	graph g(4, 5);
	forn(i, 5) {

		ll a, b; cin >> a >> b;
		g.addEdge(a, b);
	}
	g.bfs(0);
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