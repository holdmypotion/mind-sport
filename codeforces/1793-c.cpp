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
typedef priority_queue<int> mx32;
typedef priority_queue<ll> mx64;
typedef priority_queue<int, v32, greater<int>> mn32;
typedef priority_queue<ll, v64, greater<ll>> mn64;
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

void potion() {
  int n; cin >> n;
  v32 a(n); forn(i, n) cin >> a[i];

  mx32 mx; mn32 mn;
  
  for (auto e: a) {
    mn.push(e);
    mx.push(e);
  }
  
  int l = 0, r = n-1;
  while (l <= r) {
    int cmin = mn.top(), cmax = mx.top();
    if (a[l] != cmin && a[l] != cmax && a[r] != cmin && a[r] != cmax) {
      p(l+1, r+1);
      return;
    } else {
      if (a[l] == cmin) {
        l++; mn.pop(); 
      } else if(a[l] == cmax) {
        l++; mx.pop();
      }
      if (a[r] == cmin) {
        r--; mn.pop();
      } else if (a[r] == cmax) {
        r--; mx.pop();
      }
    }
  }
  p(-1);
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

