// n-1 = (2^r)*d, a = rnd[2..n-2] as witness number
bool isProbablyPrime(ll a){
	a = fast(a,d,n); if(a == 1)return true;
	FOR(i,r){
		if(i)a = multiply(a,a,n);
		if(a == n-1)return true;
	}
	return false;
}
bool isPrime(ll n, int iteration, bool res = true){
	ll d = n-1, r = 0; while(d%2 == 0) d /= 2, r++;
	FOR(i,iteration) res &= isProbablyPrime(a);
	return res;
}