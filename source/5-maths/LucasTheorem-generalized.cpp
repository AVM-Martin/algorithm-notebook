// Special Lucas : (n,k) % p^x
// fctp[n] =  Product of the integers less than or equal to n that
// are not divisible by p;   Precompute fctp
ll p;
ll E(ll n, int m){
	ll tot = 0;  while(n!=0) tot += n/m, n /= m;  return tot;
}
ll funct(ll n, ll base){
	ll ans = fast(fctp[base], n/base, base);
	return (ans * fctp[n%base]) % base;
}
ll F(ll n, ll base){
	ll ans = 1;  while(n!=0) ans=(ans*funct(n,base))%base, n/=p;
	return ans;
}
ll special_lucas(ll n, ll r, ll base){
	p = fprime(base);
	ll pow = E(n,p)-E(n-r,p)-E(r,p);
	ll TOP = fast(p,pow,base) * F(n,base) % base;
	ll BOT = F(r,base) * F(n-r,base) % base;
	return (TOP * fast(BOT,totien(base)-1,base)) % base;
}
