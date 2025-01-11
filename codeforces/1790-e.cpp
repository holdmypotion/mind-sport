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
  ll x; cin >> x;
  // Choosing the min numbers that'll form xor for x
  // We'll loop through and go from 32 bits to 0.
  // Setting bits that are currently 0 (that means it has to be same in both a and b) to 1
  // We only set it to 1 iff the sum of a+b after setting isn't exceeding 2*x
  ll a = x;
  ll b = 0;
  rforsn(i, 29, 0) {
    if ((x & (1 << i)) > 0 ) continue;
    if (2*x >= (a^(1<<i))+(b^(1<<i))) {
      a ^= (1 << i);
      b ^= (1 << i);
    }
  }
  if ((a+b==2*x) && (a^b==x)) p(a, b);
  else p(-1);
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

