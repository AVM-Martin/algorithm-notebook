long long pollard_rho(long long n){
	for (long long d=n,int c=2; d==n; c++) {
		long long x = 2, y = 2;
		do{ // using Russian peasant
			x = (multiply(x,x,n)+c) % n;
			y = (multiply(y,y,n)+c) % n;
			y = (multiply(y,y,n)+c) % n;
		} while ((d = gcd(abs(x-y),n)) <= 1);
	} pollard_rho(d);  pollard_rho(n/d);
}
