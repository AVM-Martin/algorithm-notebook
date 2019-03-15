ll pollard_rho(ll n){
	for(ll d=n,int c=2; d==n; c++){
		ll x = 2, y = 2;
		do{ // Russian peasant
			x = (mulmod(x,x,n)+c) % n;
			y = (mulmod(y,y,n)+c) % n;
			y = (mulmod(y,y,n)+c) % n;
			d = gcd(abs(x-y),n);
			if(d>1)break;
		} while(1);
	}
	pollard_rho(d);  pollard_rho(n/d);
}