// Special Lucas : (n,k) % p^x           fctp[n] =  Product of the integers less
// than or equal to n that are not divisible by p;   Precompute fctp
long long p;
long long E(long long n, int m) {
	long long tot = 0;  while (n != 0) tot += n/m, n /= m;  return tot;
}
long long funct(long long n, ll base) {
	long long ans = fast(fctp[base], n/base, base);
	return (ans * fctp[n%base]) % base;
}
long long F(long long n, long long base) {
	long long ans = 1;  while (n != 0) ans = (ans*funct(n,base))%base, n /= p;
	return ans;
}
long long special_lucas(long long n, long long r, long long base) {
	p = fprime(base);
	long long pow = E(n,p)-E(n-r,p)-E(r,p);
	long long TOP = fast(p,pow,base) * F(n,base) % base;
	long long BOT = F(r,base) * F(n-r,base) % base;
	return (TOP * fast(BOT,totien(base)-1,base)) % base;
}
