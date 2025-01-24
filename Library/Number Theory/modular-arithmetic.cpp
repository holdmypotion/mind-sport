ll pow(ll base, ll exp, ll mod) {
  ll result = 1;
  base %= mod;
  while(exp > 0) {
    if(exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}
