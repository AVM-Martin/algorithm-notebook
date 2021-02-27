long long multiply(__int128 a, __int128 b, __int128 mod) { return (a*b) % mod; }
long long multiply(long long a, long long b, long long mod, long long res = 0) {
	for(; b; b>>=1, a=(a<<1)%mod) res = (res + (b&1) * a) % mod;
	return res;
} // don't forget to re-change the modulo to a simple if
