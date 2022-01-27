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
	ll n, m, timer;
	vvp64 adj;
	vv64 dp;
	v64 in, out, sum, weight, dist, arr;
	graph() = default;
	graph(ll n) : n(n) {
		timer = 0;
		adj.resize(n + 1);
		dp.resize(n + 1, v64(21, 0));
		in.resize(n + 1);
		out.resize(n + 1);
		sum.resize(n + 1, 0);
		dist.resize(n + 1, 0);
		weight.resize(n + 1, 0);
		arr.resize(n + 1, 0);
	}

	void addEdge(ll u, ll v, ll w) {
		adj[u].pb({ v, w });
	}

	void dfs(ll u, ll p) {
		sum[u] = sum[p] + arr[u];
		dp[u][0] = p;
		in[u] = timer++;
		for (int i = 1; i <= 20; i++) {
			dp[u][i] = dp[dp[u][i - 1]][i - 1];
		}
		for (auto& v : adj[u]) {
			int a = v.fi, wt = v.se;
			if (a != p) {
				dist[a] = dist[u] + wt;
				weight[a] = weight[u] + (dist[a] * arr[a]);
				dfs(a, u);
			}
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
		for (ll i = 20; ~i; i--) {
			// cout << ~i << ln;
			if (!is_ancestor(dp[u][i], v)) {
				u = dp[u][i];
			}
		}
		// u = not is_ancestor of v;
		return dp[u][0]; // parent of u is lca
	}

	ll calculate_dist(ll x, ll y) {
		int k = lca(x, y);
		int node_is_lca = (dist[x] - dist[y]) * arr[k];
		int ans1 = (sum[x] - sum[k]) * (dist[x] - dist[y] + 2 * dist[k]) - 2 * (weight[x] - weight[k]);
		int ans2 = (sum[y] - sum[k]) * (dist[x] - dist[y] - 2 * dist[k]) + 2 * (weight[y] - weight[k]);
		int ans = ans1 + ans2 + node_is_lca;
		return ans;
	}

};
// solution
void potion() {
	ll n, q; cin >> n >> q;
	graph g(n);
	forsn(i, 1, n + 1) cin >> g.arr[i];
	forsn(i, 1, n) {
		// we are getting parents for each node
		int u, v, w; cin >> u >> v >> w;
		g.addEdge(u, v, w);
		g.addEdge(v, u, w);
	}
	g.dfs(1, 1);

	while (q--) {
		ll u, k; cin >> u >> k;
		ll ans = g.calculate_dist(u, k);
		cout << ans << endl;
	}
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