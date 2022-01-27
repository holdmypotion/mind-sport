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


struct grid {
	int n, m;
	p32 src;
	vector<string> adj;
	queue<p32> q;
	vv32 nex;

	int dr[4] = { 0, 0, 1, -1 };
	int dc[4] = { 1, -1, 0, 0 };
	string ds = "RLDU";

	grid() = default;
	grid(int n, int m) : n(n), m(m) {
		adj.resize(n);
		nex.resize(n + 1, v32(m + 1, 0));
	}

	//! Customize according to question
	void fillgrid() {
		for (auto& ele : adj) cin >> ele;

		forn(i, n) {
			forn(j, m) {
				if (adj[i][j] == 'M') q.push({ i, j });
				else if (adj[i][j] == 'A') src = { i, j };
			}
		}
		q.push(src);
	}

	bool isValid(int x, int y) {
		bool possible = (x < n&& x >= 0 && y < m&& y >= 0);
		if (!possible || adj[x][y] != '.') return false;
		return true;
	}

	void escapeRoute() {
		nex[src.fi][src.se] = -1;
		while (!q.empty()) {
			auto [x, y] = q.front(); q.pop();
			if (adj[x][y] == 'A' && (x == 0 || x == n - 1 || y == 0 || y == m - 1)) {
				cout << "YES" << ln;
				string ans;
				int d = nex[x][y];
				while (d != -1) {
					ans += ds[d];
					x -= dr[d];
					y -= dc[d];
					d = nex[x][y];
				}
				reverse(all(ans));
				cout << ans.size() << ln << ans;
				return;
			}

			forn(i, 4) {
				int nx = x + dr[i], ny = y + dc[i];
				if (isValid(nx, ny)) {
					adj[nx][ny] = adj[x][y];
					// cout << nx << " " << ny << ": " << i << ln;
					if (adj[nx][ny] == 'A') nex[nx][ny] = i;
					q.push({ nx, ny });
				}
			}
		}
		cout << "NO";
	}
};

// solution
void potion() {
	ll n, m; cin >> n >> m;
	grid g(n, m);
	g.fillgrid();
	g.escapeRoute();
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