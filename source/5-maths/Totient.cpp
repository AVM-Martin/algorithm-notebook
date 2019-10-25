// count x < n that are coprime to n
int phi(int n) { // n * PHI( 1 - 1/pf )
	if (n == 1) return 0;     int res = n;
	for (int i=2; i<=n/i; i++) {
		if (n%i == 0) res -= res/i;     while (n % i == 0) n /= i;
	} return res - ( n!=1 ? res/n : 0 );
}
vector<int> sieve_phi(int n) { // sieve version
	vector<bool> is_prime(n+1,true);  vector<int> ret(n+1);
	for (int i=0; i<n; i++) ret[i] = i;
	for (int i=2; i<=n; i++) if(is_prime[i]) for (int j=i; j<=n; j+=i) {
		ret[j] -= ret[j]/i, is_prime[j] = false;
	}
	return ret;
}
void sievephi(int n) {
	phi[1] = 0;  for (long long i=2; i<n; i++) phi[i] = i;
	for (long long i=2; i<=n; i+=(i==(ll)2)?1:(ll)2) if (phi[i] == i) {
		for (long long j=i; j<=n; j+=i) phi[j] = phi[j]*(ll)(i-(ll)1)/(ll)i;
	}
	for (long long i=2; i<=n; i++) for(long long j=1,_n=n/i; j<=_n; j++) {
		ans[i*j] += j*phi[i];
	}
	for (long long i=2; i<=n; i++) ans[i] += ans[i-1];
}
int phi(int n) {
	if (n == 1) return 0;     int res = n;
	for (int i=2; i<=n/i; i+=(i==2?1:2)) {
		if(n%i) continue;     while (n > 1 && n % i == 0) n /= i;
		res = (res % i) ? res * (i-1)/i : res/i * (i-1);
	}
	if(n > 1) res = res/n * (n-1);     return res;
}
