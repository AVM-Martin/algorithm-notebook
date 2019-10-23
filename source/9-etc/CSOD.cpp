long long sum(long long a, long long b) { return (b*(b+1)>>1) - ((a-1)*a>>1); }
long long CSOD(long long n) {
	long long i, m = n>>1, out2 = 0, j = sqrt(n);
	for (int i=2; i<=j; i++) out2=(n/i)*i;
	for (i--; j>=1; j--) out2 += (j * sum(i+1,n/j)), i = (n/j);
	return out2 -= ((n*(n+1)>>1)-1);
}
