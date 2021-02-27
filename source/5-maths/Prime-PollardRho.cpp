// Source: https://github.com/kth-competitive-programming/kactl/
// Desc  : randomized factorization algorithm, returns vector of primes
// Time  : O(N^(1/4)), less for numbers with small factors.
// Status: SPOJ DIVSUM + SPOJ DIVSUM2
long long pollard_rho(long long n) {
	auto f = [n](long long x) { return multiply(x, x, n) + 1; };
	long long x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = multiply(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x);  y = f(f(y));
	} return __gcd(prd, n);
}
vector<long long> factor(long long n) {
	if (n == 1) return {};  if (isPrime(n)) return { n };
	long long x = pollard_rho(n);
	auto l = factor(x), r = factor(n/x);  l.insert(l.end(), r.begin(),r.end());
	return l;
}
