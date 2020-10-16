// For NTT, let p = (2^k)*c + 1 be modulo prime and size of polynom <= 2^k
// do not forget divmod and other mods
//  998244353 = 119 * 2**23 + 1. Primitive root: 3.
//  985661441 = 235 * 2**22 + 1. Primitive root: 3.
// 1012924417 = 483 * 2**21 + 1. Primitive root: 5.
typedef complex<double> cpx;  typedef vector<cpx> vec; // cpx => ll
void FFT(vec& a, int sign = 1) {
	int n = a.size();
	double theta = sign * TAU / n;
	// ll theta = fastExp(prr, (MOD-1)/n);
	// if(sign == -1) theta = fastExp(theta, MOD-2);
	for (int i=0,j=1; j<n-1; j++) {
		for (int k=n>>1; k>(i^=k); k>>=1);
		if (j<i) swap(a[i],a[j]);
	}
	for (int m,mh=1; (m=mh<<1)<=n; mh=m) {
		int irev = 0;
		for (int i=0; i<n; i+=m) {
			cpx w = exp(cpx(0,theta*irev));  // from e^(i*theta)
			// ll w = fastExp(theta, irev);  // pre-compute
			for (int k=n>>2; k>(irev^=k); k>>=1);
			for (int j=i; j<mh+i; j++) { // modulo party here
				int k = j+mh;  cpx x = a[j]-a[k];  a[j] += a[k];  a[k] = w*x;
	}	}	}
	if (sign == -1) for (int i=0; i<n; i++) a[i] /= n; // fastExp(n, MOD-2)
}
void polyMultiplication(vec& res, vec& a, vec& b) {
	res.clear();  int n = a.size() + b.size() - 1;
	for (int i=1; i<=n-1; i+=i) if(n&i) n += i;
	a.resize(n);  b.resize(n);   FFT(a);  FFT(b);
	for (int i=0; i<n; i++) res.push_back(a[i]*b[i]);  FFT(res,-1);
} // result: res (in vec) => (int)(real(x) + (double)0.5)
