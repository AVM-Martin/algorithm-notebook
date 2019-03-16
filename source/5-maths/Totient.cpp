// count x < n that are coprime to n
int phi(int n){ // n * PHI( 1 - 1/pf )
	if(n == 1) return 0;     int res = n;
	REP(i,2,n/i){
		if(n%i == 0) res -= res/i;     while(n%i == 0) n /= i;
	} return res - ( n!=1 ? res/n : 0 );
}
vi sieve_phi(int n){ // sieve version
	vector<bool> is_prime(n+1,true);  vi ret(n+1);
	FOR(i,n) ret[i] = i;
	REP(i,2,n) if(is_prime[i]) REPP(j,i,n,i)
		ret[j] -= ret[j]/i, is_prime[j] = false;
	return ret;
}
void sievephi(int n){
	phi[1] = 0;  for(LL i=2; i<n; i++)phi[i] = i;
	REPP((ll)i, 2,n, (i==(ll)2)?1:(ll)2) if(phi[i] == i)
		REPP((ll)j, i,n, i) phi[j] = phi[j]*(ll)(i-(ll)1)/(ll)i;
	REP((ll)i,2,n) for(ll j=1,_n=n/i; j<=_n; j++)
		ans[i*j] += j*phi[i];
	REP((ll)i,2,n) ans[i] += ans[i-1];
}
int phi(int n){
	if(n == 1) return 0;     int res = n;
	REPP(i,2,n/i,(i==2?1:2)){
		if(n%i) continue;     while(n>1 && n%i==0) n/=i;
		res = (res%i) ? res*(i-1)/i : res/i*(i-1);
	}
	if(n > 1) res = res/n*(n-1);     return res;
}