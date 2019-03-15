long sumsLowerBound(long[] A, long B){
	int n = A.length;
	int sizeL = 1<<(n/2), sizeR = 1<<(n-n/2);
	long[] SumsL = new long[sizeL];
	long[] SumsR = new long[sizeR];
	FOR(i,sizeL) FOR(j,n/2) if((i&(1<<j)) > 0)
		SumsL[i] += A[j];
	FOR(i,sizeR) FOR(j,n-n/2) if((i&(1<<j)) > 0)
		SumsR[i] += A[j+n/2];
	Arrays.sort(SumsL);  Arrays.sort(SumsR);
	int PL = 0, PR = sizeR-1;
	long cur=Long.MIN_VALUE;
	while(PL<sizeL && PR >= 0){
		if(SumsL[PL]+SumsR[PR] <= B)
			cur = Math.max(cur,SumsL[PL++]+SumsR[PR]);
		else PR--;
	}
	return cur;
}