
bool isprime(ll n) {
  if (n < 2) return false;
  for (int x = 2; x * x <= n; x++) {
    if (n % x == 0) return false;
  }
  return true;
}

v64 factors(ll n) {
  v64 f;
  for (int x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      f.pb(x); // x is a factor
      n /= x;  // to get factors apart from x
    }
  }
  if (n > 1) f.pb(n); // residual n is prime

  return f;
}

v64 sieve(ll n) {
  v64 s(n);
  forn(x, 2, n+1) {
    // doing 2*u to skip the prime number like 2 and
    // start from the factors like 4, 8, ...
    if (s[x]) = continue;
    for (ll u=2*u; u <= n; u += x) {
      s[u] = x;
    }
  }
  return s;
}

