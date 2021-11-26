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
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
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

auto mpow(ll base, ll exp) {
	ll result = 1;
	while (exp) {
		if (exp & 1) (result *= base) %= MOD;
		(base *= base) %= MOD;
		exp >>= 1;
	}
	return result;
}

auto inverse(int i) {
	return mpow(i, MOD - 2);
}

struct hash_t {
	string s;
	ll n, p, invp;
	v64 hash, invhash, power, invpower;
	hash_t() = default;
	hash_t(string s) : s(s), n(s.length()) {
		hash.assign(n, 0);
		invhash.assign(n, 0);
		power.assign(n, 1);
		invpower.assign(n, 1);
	}
	void init() {
		// p = 2 * rng(13, 1e8) + 1;
		p = 29;
		invp = inverse(p);
		forn(i, n) {
			power[i] = ((i ? power[i - 1] : (int)1) * p) % MOD;
			invpower[i] = ((i ? invpower[i - 1] : (int)1) * invp) % MOD;
			hash[i] = ((i ? hash[i - 1] : (int)0) + (s[i] - 'a' + 1) * power[i]) % MOD;
			invhash[i] = ((i ? invhash[i - 1] * p : (int)0)) + (s[i] - 'a' + 1);
			hash[i] %= MOD;
			invhash[i] %= MOD;
		}
	}
	ll gethash(ll l, ll r) {
		ll f = (hash[r] - (l ? hash[l - 1] : (ll)0));
		if (f < 0) f += MOD;
		f *= invpower[l];
		return f % MOD;
	}
	ll getinvhash(ll l, ll r) {
		ll f = invhash[r] - (l ? invhash[l - 1] * power[r - l] % MOD : (ll)0);
		return (f % MOD + MOD) % MOD;
	}
};

// solution
void potion() {
	string s; cin >> s;
	ll n = s.length();
	hash_t f(s); f.init();
	int l = 0, r = n - 1;
	v32 ans;
	while (l < n - 1 && r > 0) {
		ll prefix = f.gethash(0, l), suffix = f.gethash(r, n - 1);
		if (prefix == suffix) {
			ans.pb(l + 1);
		}
		l++;r--;
	}
	for (auto& it : ans) cout << it << " ";
}

int main() {
	fast_cin();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	// cin >> t;
	while (t--) potion();
	return 0;
} // Alright then, mate