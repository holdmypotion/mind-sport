// * Problem Statement
// You have a sequence of N distinct elements. Find the length of the 
// longest subsequence such that each successive element is a multiple of the
// element before it (if exists) in the subsequence.

// Input:
// The first line consists of N, the number of elements in the sequence.
// The next line consists of N space-separated integers, the contents of the sequence.

// Output:
// Print a single integer, consisting of the answer to the given input instance.

// Constraints:
// 1 <= N <= 104
// 1 <= A[i] <= 106

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

int count = 1, max_count = 1;

void longest_subsequence(int i, int n, vvb& dp) {
	max_count = max(max_count, ::count);
	for (int j = i + 1; j < n; j++) {
		// if jth is multiple of ith 
		if (dp[i][j]) {
			::count++;
			// now check the longet sequence starting from jth element
			longest_subsequence(j, n, dp);
		}
	}
	// backtrack
	::count = 1;
}

// solution
void potion() {
	int n; cin >> n;
	vector<vector<bool>> dp(n, vector<bool>(n, 0));
	vector<int> arr(n);
	for (auto& ele : arr) cin >> ele;

	// dp[i][j] = mark all the multiples in sequential order as true
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == 1 || arr[j] >= arr[i] && arr[j] % arr[i] == 0) {
				dp[i][j] = true;
			}
		}
	}

	// count the longest subsequence starting from the ith element
	for (int i = 0; i < n - 1; i++) {
		longest_subsequence(i, n, dp);
	}
	cout << max_count << ln;
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