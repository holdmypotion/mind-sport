// author: holdmypotion
#pragma GCC optimize("Ofast")
/* #pragma GCC target("sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma") */
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<char>> vvc;
typedef vector<vector<p32> > vvp32;
typedef vector<vector<p64> > vvp64;
typedef vector<vector<bool>> vvb;
typedef priority_queue<int> mx32;
typedef priority_queue<ll> mx64;
typedef priority_queue<int, v32, greater<int>> mn32;
typedef priority_queue<ll, v64, greater<ll>> mn64;
typedef vector<p64> vp64;
typedef vector<t64> vt64;
typedef vector<p32> vp32;
typedef set<p32> sp32;
typedef set<p64> sp64;
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

template<typename... T>
void p(T... args) { ((cout << args << " "), ...) << "\n"; }

template <typename T>
void pv(const vector<T>& vec) {
  for (const auto& elem : vec) cout << elem << " ";
  cout << ln;
}

template <typename T>
void pvv(const vector<T>& vv) {
  for (const auto& v : vv) {
    for (const auto& e : v) cout << e << " ";
    cout << ln;
  }
}

// 0 -> not visited
// 1 -> visited but yet to be marked
// 2 -> visited but is a cycle
// 3 -> visited but leads out

ll dfs(ll i, ll j, ll& r, ll& c, vv64 &dp, vs& g) {
  if (i < 0 || i >= r || j < 0 || j >= c) return 2;
  if (dp[i][j] == 1) return 3;
  if (dp[i][j] > 1) return dp[i][j];

  dp[i][j] = 1;

  ll result;
  if (g[i][j] == 'U') { result = dfs(i-1, j, r, c, dp, g); }
  else if (g[i][j] == 'D') { result = dfs(i+1, j, r, c, dp, g); }
  else if (g[i][j] == 'L') { result = dfs(i, j-1, r, c, dp, g); }
  else if (g[i][j] == 'R') { result = dfs(i, j+1, r, c, dp, g); }
  else if (g[i][j] == '?') {
    result = max({
      dfs(i+1, j, r, c, dp, g),
      dfs(i-1, j, r, c, dp, g),
      dfs(i, j-1, r, c, dp, g),
      dfs(i, j+1, r, c, dp, g)
    });
  };

  return dp[i][j] = result;
}

void potion() {
  ll r, c; cin >> r >> c;
  vs g(r); forn(i, r) cin >> g[i];

  vv64 dp(r, v64(c, 0));
  
  forn(i, r) {
    forn(j, c) {
      dfs(i, j, r, c, dp, g);
    }
  }

  // pvv(dp);

  ll count = 0;
  forn(i, r) {
    forn(j, c) {
      if(dp[i][j] == 3) count++;
    }
  }
  p(count);
}

signed main() {
  fast_cin();
#ifndef ONLINE_JUDGE
  freopen("/Users/loona-mac/personal/mind-sport/input.txt", "r", stdin);
  // freopen("/Users/loona-mac/personal/mind-sport/output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) potion();
  return 0;
}

