// For NTT, let p = (2^k)*c + 1 be modulo prime
// need: size of polynom <= 2^k
// find prr (roots) => prr^1 .. prr^p-1 distinct
// dont forget divmod and other mods
typedef complex<double> cpx;  typedef vector<cpx> vec;
void FFT(vec& a, int sign = 1){
	int n = a.size();
	double theta = sign * TAU / n;
	// ll theta = fastExp(prr, (MOD-1)/n);
	// if(sign == -1) theta = fastExp(theta, MOD-2);
	for(int i=0,j=1; j<n-1; j++){
		for(int k=n>>1; k>(i^=k); k>>=1);
		if(j<i) swap(a[i],a[j]);
	}
	for(int m,mh=1; (m=mh<<1)<=n; mh=m){
		int irev = 0;
		for(int i=0; i<n; i+=m){
			cpx w = exp(cpx(0,theta*irev)); //e^(i*theta)
			// ll w = fastExp(theta, irev); pre-compute
			for(int k=n>>2; k>(irev^=k); k>>=1);
			for(int j=i; j<mh+i; j++){
				int k = j+mh;
				cpx x = a[j]-a[k];
				a[j] += a[k];
				a[k] = w*x;
	}   }   }
	if(sign == -1) FOR(i,n) a[i] /= n;
}
void polyMultiplication(vec& res, vec& a, vec& b){
	res.clear();  int n = a.size()+b.size()-1;
	REPP(i,1,n-1,i) if(n&i) n += i;
	a.resize(n);  b.resize(n);   FFT(a);  FFT(b);
	FOR(i,n) res.pb(a[i]*b[i]);  FFT(res,-1);
} // result: res (in vec) => (int)(real(x) + (double)0.5)