ll sum(ll a, ll b){
	return (b*(b+1)>>1) - ((a-1)*a>>1);
}
ll CSOD(LL n){
	ll i, m = n>>1, out2 = 0, j = sqrt(n);
	REP(i,2,j) out2=(n/i)*i;
	for(i--;j>=1;j--)
		out2 += (j*sum(i+1,n/j)), i=(n/j);
	return out2 -= ((n*(n+1)>>1)-1);
}