// num-1 = (2^r)*d, a = random[2..num-2] as witness number
bool isProbablyPrime(ll a){ // remember: a is witness number
	a = fast(a,d,num); if(a == 1) return true;
	FOR(i,r){
		if(i) a = multiply(a,a,num);
		if(a == num-1) return true;
	}
	return false;
}
bool isPrime(ll num, int iteration, bool res = true){
	ll d = num-1, r = 0;  while(d%2 == 0) d >>= 1, r++;
	FOR(i,iteration) res &= isProbablyPrime(a);
	return res;
}
