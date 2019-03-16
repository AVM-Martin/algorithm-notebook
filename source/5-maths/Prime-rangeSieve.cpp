void sieve(int L, int U, vector<int>& primes){
	memset(isnp,0,sizeof(isnp));  int nto = U-L+1;
	for(auto nP: primes){
		if(nP > U/nP) break;
		int fnum = (L/nP)*nP;
		if(fnum < L) fnum += nP;
		if(fnum == nP) fnum += nP;
		REPP(k,fnum-L,nto,nP) isnp[k] = 1;
	}
	if(L <= 1) isnp[1-L] = 1;
	if(L <= 0) isnp[0-L] = 1;
}