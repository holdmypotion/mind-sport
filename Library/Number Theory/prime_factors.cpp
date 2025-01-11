
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
