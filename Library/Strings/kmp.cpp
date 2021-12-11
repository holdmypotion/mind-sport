
/*
 * Sample Inputs
1
ababdabcabababd
ababd
*/

// solution
void potion() {
	string s, p, t; cin >> s >> p;
	t = "$" + p + "$" + s;
	ll n = t.length(), m = p.length(), pi[n + 1]{}, count = 0;
	// $ababd$ababdabcabababd
	for (ll i = 2, k = 0; i <= n; i++) {  // 1-based indexing
		while (k > 0 && t[i] != t[k + 1]) k = pi[k];
		if (t[i] == t[k + 1]) {
			k++;

			if (i > m && k == m) count++;
		}
		if (i <= m) pi[i] = k;
	}

	cout << count << ln;
}
