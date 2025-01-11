// seed_seq seed{
// 	(uint64_t)chrono::duration_cast<chrono::nanoseconds>
// 	(chrono::high_resolution_clock::now().time_since_epoch()).count(),
// 	(uint64_t)__builtin_ia32_rdtsc(),
// 	(uint64_t)(uintptr_t)make_unique<char>().get()
// };



// mt19937_64 mersenne(seed);



// ll rng(ll l, ll r) {
// 	return uniform_int_distribution<ll>(l, r)(mersenne);
// }

auto binpow(ll base, ll exp) {
  ll result = 1;
  while (exp) {
    if (exp & 1) (result *= base) %= MOD;
    (base *= base) %= MOD;
    exp >>= 1;
  }
  return result;
}

auto inverse(ll i) {
  return binpow(i, MOD - 2);
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
    invp = inverse(p); // 1/29
    forn(i, n) {
      power[i] = ((i ? power[i - 1] : (ll)1) * p) % MOD;
      invpower[i] = ((i ? invpower[i - 1] : (ll)1) * invp) % MOD;
      hash[i] = ((i ? hash[i - 1] : (ll)0) + (s[i] - 'a' + 1) * power[i]) % MOD;
      // invhash[i] = ((i ? invhash[i - 1] * p : (ll)0)) + (s[i] - 'a' + 1);
      hash[i] %= MOD;
      // invhash[i] %= MOD;
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
