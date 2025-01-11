// author: holdmypotion
#pragma GCC optimize("Ofast")
/* #pragma GCC target("sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma") */
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

enum COLOR { WHITE, GRAY, BLACK };

struct graph {
  ll n, m;
  vv64 adj;
  vector<set<ll>> reach;
  v64 color, backedge;
  graph() = default;
  graph(ll n, ll m) : n(n), m(m) {
    adj.resize(n + 1);
    reach.resize(n + 1);
    color.resize(n + 1, WHITE);
    backedge.resize(n + 1, 0);
  };

  void addEdge(ll u, ll v) {
    adj[u].push_back(v);
    reach[u].insert(v);
  }

  set<ll> dfs(ll u) {
    color[u] = GRAY;
    reach[u].insert(u);
    for (auto& v : adj[u]) {
      if (color[v] == GRAY) {
        backedge[u] = (backedge[u] == 0 ? v : min(backedge[u], v));
        continue;
      }
      auto s = reach[v];
      if (color[v] == WHITE) s = dfs(v);

      if (s.size() > reach[u].size()) {
        swap(s, reach[u]);
      }
      // cout << v << ": ";
      for (auto& ele : s) {
        // cout << ele << ln;
        reach[u].insert(ele);
      }
    }
    color[u] = BLACK;
    return reach[u];
  }


  void topologicalOrder() {
    forsn(i, 1, n + 1) {
      if (color[i] == WHITE) dfs(i);
    }
    forsn(i, 1, n + 1) {
      if (backedge[i] != 0) {
        reach[i] = reach[backedge[i]];
      }
    }
    forsn(i, 1, n + 1) cout << reach[i].size() << " ";
    // forsn(i, 1, n + 1) {
    // 	cout << i << ": ";
    // 	for (auto& ele : reach[i]) cout << ele << " ";
    // 	cout << ln;
    // }
  }
};

// solution
void potion() {
  ll n, m; cin >> n >> m;
  graph g(n, m);
  forn(i, m) {
    ll u, v; cin >> u >> v;
    g.addEdge(u, v);
  }

  g.topologicalOrder();
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
