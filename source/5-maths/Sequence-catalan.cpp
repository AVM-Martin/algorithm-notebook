ll catalan(int n){ // nCk(2n,n) / (n+1) == nCk(2n,n) - nCk(2n,n+1)
	if(n <= 1)return 1;
	return c(n-1) * 2 * (2*n-1) / (n+1);
} // 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012
ll superCat(int n){ // nCk(2m,m) * nCk(2n,n) / nCk(m+n,m)
	if(n <= 1) return 1;
	return (3*(2*n-1)*superCat(n-1) - (n-2)*superCat(n-2)) / (n+1);
} // 1, 1, 3, 11, 45, 197, 903, 4279, 20793, 103049, 518859, 2646723
