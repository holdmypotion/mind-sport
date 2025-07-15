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
  // * As both play optimally
  // * Player 1 -> wants to maximize score1 - score2
  // * Player 2 -> wants to minimize score1 - score2
  // ? Hence, there choices at each stage should be same, i.e. optimal.
  // state: dp[l][r] -> max difference (score1-score2) if considering the interval [l, r]
  // transition: dp[l][r] = max(nums[l] - dp[l+1][r], nums[r] - dp[l][r-1]);
  // As dp[l+1][r] contains the optimal choice taken if it was player1's turn
  // Hence dp[l+1][r] will be player2's best option as well.
  // ? score1 reduces by nums[l] - dp[l+1][r]

  int n; cin >> n;
  v32 nums(n);
  ll sum = 0;
  for (auto& ele : nums) {
    cin >> ele;
    sum += ele;
  }

  vv64 dp(n, v64(n));
  for (int l = n - 1; l >= 0;l--) {
    for (int r = l; r < n; r++) {
      if (l == r) {
        dp[l][r] = nums[l];
      }
      else {
        dp[l][r] = max(nums[l] - dp[l + 1][r], nums[r] - dp[l][r - 1]);
      }
      cout << dp[l][r] << ln;
    }
  }
  // sum = score1 + score2
  // dp[0][n-1] = score1 - score2
  // hence (sum + dp[0][n-1]) / 2 -> score1
  cout << dp[0][n - 1] << ln;
  cout << (sum + dp[0][n - 1]) / 2;
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
