ll multiply(ll a, ll b, ll M, ll res = 0){
	for(; b; b>>=1, a=(a<<1)%M) res = (res + (b&1)*a) % M;
	return res;
} // don't forget to re-change the modulo to a simple if