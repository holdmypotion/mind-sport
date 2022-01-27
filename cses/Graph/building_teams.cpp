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
	vv64 adj;
	vb vis;
	v64 group;

	graph() = default;
	graph(ll n) : n(n) {
		adj.resize(n + 1);
		vis.resize(n + 1, false);
		group.resize(n + 1, 0);
	}
	graph(ll n, ll m) : n(n), m(m) {
		adj.resize(n + 1);
		vis.resize(n + 1, false);
		group.resize(n + 1);
	}

	void addedge(ll a, ll b) {
		adj[a].pb(b);
	}

	bool bfs(ll u) {
		queue<ll> q;
		q.push(u);
		vis[u] = true;
		if (group[u] == 0) group[u] = 1;
		while (!q.empty()) {
			auto s = q.front();q.pop();
			for (auto& v : adj[s]) {
				if (group[v] == group[s]) return false;
				if (!vis[v]) {
					group[v] = (group[s] == 1 ? 2 : 1);
					vis[v] = true;
					q.push(v);
				}
			}
		}
		return true;
	}

	void groupthem() {
		forsn(i, 1, n + 1) {
			if (!bfs(i)) {
				cout << "IMPOSSIBLE";
				return;
			}
		}
		forsn(i, 1, n + 1) cout << group[i] << " ";
	}
};

// solution
void potion() {
	ll n, m; cin >> n >> m;
	graph g(n, m);
	forn(i, m) {
		int a, b; cin >> a >> b;
		g.addedge(a, b);
		g.addedge(b, a);
	}
	g.groupthem();
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