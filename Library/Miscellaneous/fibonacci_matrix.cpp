constexpr ll n = 2;

vv64 identity(ll n) {
  vv64 id(n, v64(2));
  for (int i = 0; i < n; i++) id[i][i] = 1;
  return id;
}

vv64 mul(vv64 a, vv64 b) {
  vv64 c(n, v64(2));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      for (ll k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}

vv64 power(vv64 base, ll exp) {
  vv64 res = identity(n);
  while (exp) {
    if (exp & 1) res = mul(res, base);
    base = mul(base, base);
    exp >>= 1;
  }

  return res;
}

// solution
void potion() {
  ll n; cin >> n;
  vv64 T(n, v64(2));
  T[0] = { 1, 1 };
  T[1] = { 1, 0 };
  v64 f = { 1, 1 };

  if (n <= 1)
  {
    cout << f[n] << ln;
    return;
  }
  T = power(T, n - 1);
  cout << f[0] * T[0][0] + f[1] * T[0][1] << "\n";
}
