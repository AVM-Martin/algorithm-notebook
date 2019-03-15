typedef vector< vector<double> > Matrix;  Matrix M;

bool Gaussian () {
	int N = M.size();
	FOR(i,N){
		int idx = -1;
		REP(j,i,N-1) if(fabs(M[j][i])>EPS)
			idx = j, break;
		if(idx == -1){ return false; }
		REP(j,i,N)swap(M[i][j],M[idx][j]);
		REV(j,N,i)M[i][j] /= M[i][i];
		REP(j,i+1,N-1) REV(k,N,i)
			M[j][k] -= M[j][i]*M[i][k];
	}
	FORD(i,N+1) FOR(j,i) REV(k,N,i)
		M[j][k] -= M[j][i]*M[i][k];
	return true;
}