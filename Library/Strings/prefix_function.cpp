/*
 * Sample Inputs
5
abcabcd
abcabab
abcabcabcaba
abababd
ababcabcabababd
*/

// solution
void potion() {
  string s; cin >> s;
  ll n = s.length(), pi[n + 1]{};
  s = "$" + s; // $ababcabcabababd

  for (ll i = 2, k = 0; i <= n; i++) {  // 1-based indexing
    while (k > 0 && s[i] != s[k + 1]) k = pi[k];
    if (s[i] == s[k + 1]) k++;
    pi[i] = k;
  }
  for (auto& ele : s) cout << ele << " ";
  cout << ln;
  for (auto& ele : pi) cout << ele << " ";
  cout << ln << ln;
}
