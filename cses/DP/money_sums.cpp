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

// solution
void potion() {
  // state: dp[i][j] -> is it possible to make j sum with first i coins
  // transition: dp[i][j] = d[i-1][j]; -> include the previous answers
  // dp[i][j] = true if (dp[i-1][j - coins[i-1]]) =>
  // it is possible to make sum j if j - coins[i-1] is already made by previous coins
  int n; cin >> n;
  v32 coins(n);
  int mxn = 0;
  for (auto& ele : coins) {
    cin >> ele;
    mxn += ele;
  }

  vvb dp(n + 1, vb(mxn + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= mxn; j++) {
      dp[i][j] = dp[i - 1][j];
      int left = j - coins[i - 1];
      if (left >= 0 && dp[i - 1][left]) dp[i][j] = true;
    }
  }

  // for (int i = 0; i <= n; i++) {
  // 	for (int j = 0; j <= mxn; j++) cout << dp[i][j] << " ";
  // 	cout << ln;
  // }

  v32 ans;
  for (int j = 1; j <= mxn; j++) {
    if (dp[n][j]) ans.pb(j);
  }

  cout << ans.size() << ln;
  for (auto& ele : ans) cout << ele << " ";
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
