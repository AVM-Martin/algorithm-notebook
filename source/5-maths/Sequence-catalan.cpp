ll superCatalan(int n){
	if(n <= 2)return 1;
	return (3*(2*n-3)*sc(n-1)-(n-3)*sc(n-2)) / n;
} // 1,1,1,3,11,45, 197, 903, 4279, 20793, 103049
ll catalan(int n){ // nCk(2n,n) / (n+1)
	if(n <= 1)return 1;
	return c(n-1) * 2 * (2*n-1) / (n+1);
} // 1,1,2,5,14,42, 132, 429, 1430, 4862, 16796