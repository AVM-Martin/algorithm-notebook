// Assume that f(0)=1 and 0^0=1.  f(n) = (n%10)^f(n/10) for all n bigger than
// zero. Please calculate f(n)%m. (2 <= n, m <= 10^9)
long long inverse(long long a, long long m) { return mPow(a,phi(m)-1,m); }
long long CRT( vector< pair<long long,int> > data ) {
	long long M = 1;  for (auto x: data) M *= x.se;
	long long ret = 0;
	for (auto x: data) {
		long long temp = x.fi * (M/x.se) * inverse(M/x.se, x.se);
		ret = (ret + temp) % M;
	}
	return ret;
}
int nums[16], n;  const int LIM = 1<<10;
long long brute(long long base, int pos, long long M) {
	if (pos == n) return base % M;
	int j = n;  long long pj = 1;
	while (j-1 >= pos) {
		long long k = 1;
		for (int loop=0; loop<pj; loop++) if ((k *= nums[j-1]) >= LIM) return 0;
		pj = k;  j--;
	}
	return mPow(base, pj, M);
}
long long solve(int,long long);
long long doit(int, int);
pair<long long,int> solve2(int pos, long long M){
	long long a = nums[pos];
	if (GCD(a,M) == 1) {
		return make_pair(mPow(a, solve(pos+1, phi((int)M)), M), M);
	}
	return make_pair(brute(a, pos+1, M), M);
}
long long solve(int pos, long long M) {
	if (M == 1) return 0;
	if (pos == n) return 1;
	if (nums[pos] == (ll)1) return a % M;
	if (nums[pos] == (ll)0) return 0;
	long long m = M;  vector< pair<long long,int> > data;
	for (long long i=2; i*i<=m; i++) {
		if (m % i != 0) continue;
		long long p = 1;  while (m % i == 0) m /= i, p *= i;
		data.push_back(solve2(pos,p));
	}
	if (m>1) data.push_back(solve2(pos, m));
	return CRT(data);
}
void normalize() {
	nums[n] = 1;  int newN = n;
	for (int i=0; i<n; i++) {
		if (nums[i] == 1) newN = i, break;
		else if (nums[i] == 0) {
			int ctr0 = 0;  while (nums[i+ctr0] == 0) ctr0++;
			if (ctr0%2 == 0) nums[i] = 1, newN = i;
			else if (i-1 >= 0) nums[i-1] = 1, newN = i-1;
			break;
	}	}
	n = newN;  if (nums[n-1] != 1) nums[n++] = 1;
}
ll doit(int x, int m) {
	n=0;  while (x) nums[n++] = x%10, x /= 10;  normalize();  return solve(0,m);
}
int inside_main() {
	int x, m;  scanf("%d %d", &x, &m);  printf("%d\n", (int)doit(x,m));
}
