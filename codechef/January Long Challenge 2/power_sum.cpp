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

constexpr int mxn = 1e5;
// solution
void potion() {
	int n; cin >> n;
	v32 arr(n + 1);
	int sum = 0, min_index = 1, minim = INT_MAX;;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (minim > arr[i]) {
			minim = arr[i];
			min_index = i;
		}
	}

	if ((sum & (sum - 1)) == 0) { cout << 0 << ln; return; }

	// target -> what we would like the sum to be
	int bits = (int)log2(sum) + 1;
	int target = (1 << bits);

	// needed -> what we need to add to sum to make it target
	int needed = target - (sum - minim);

	// we are claiming that (target - sum) is a multiple of minim;
	// i.e. (target-sum) | M;
	int mul = needed / minim;
	cout << 1 << ln;
	cout << 1 << " " << mul << ln << min_index << ln;
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