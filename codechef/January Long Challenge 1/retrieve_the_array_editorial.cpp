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

using namespace std;
long long readInt(long long l, long long r, char endd) {
	long long x = 0;
	int cnt = 0;
	int fi = -1;
	bool is_neg = false;
	while (true) {
		char g = getchar();
		if (g == '-') {
			assert(fi == -1);
			is_neg = true;
			continue;
		}
		if ('0' <= g && g <= '9') {
			x *= 10;
			x += g - '0';
			if (cnt == 0) {
				fi = g - '0';
			}
			cnt++;
			assert(fi != 0 || cnt == 1);
			assert(fi != 0 || is_neg == false);

			assert(!(cnt > 19 || (cnt == 19 && fi > 1)));
		}
		else if (g == endd) {
			assert(cnt > 0);
			if (is_neg) {
				x = -x;
			}
			assert(l <= x && x <= r);
			return x;
		}
		else {
			assert(false);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	t = readInt(1, 200000, '\n');
	int temp = 1 << 18;
	// cout << temp << ln;
	int ns = 0;
	while (t--) {
		int n, x;
		n = readInt(1, 100000, ' ');
		x = readInt(1, 500000, '\n');
		ns += n;
		assert(ns <= 300000);
		if (n == 1) {
			cout << x << "\n";
			continue;
		}
		int ans[n];
		for (int i = 0; i < n - 1; i++) {
			x ^= i;
			ans[i] = i;
		}
		// cout << "x: " << x << ln;
		if (x >= n && x <= 500000) {
			ans[n - 1] = x;
		}
		else {
			if (x > 500000) {
				ans[n - 1] = x - temp;
			}
			else {
				ans[n - 1] = x + temp;
			}
			if (x == ans[n - 2]) {
				// if x == n-2 then ans[n-2] += temp will result into
				// ans[n-1] == ans[n-2]
				// as  ans[n-1] = x + temp
				// ans ans[n-2] = ans[n-2] + temp
				ans[0] = temp;
			}
			else {
				ans[n - 2] += temp;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}