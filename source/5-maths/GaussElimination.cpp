typedef vector< vector<double> > Matrix;  Matrix M;
bool Gaussian() {
	int N = M.size();
	for (int i=0; i<N; i++) {
		int idx = -1;
		for (int j=i; j<=N-1; j++) if (fabs(M[j][i]) > EPS) { idx = j;  break; }
		if (idx == -1) { return false; }
		for (int j=i; j<=N; j++) swap(M[i][j],M[idx][j]);
		for (int j=N; j>=i; j--) M[i][j] /= M[i][i];
		for (int j=i+1; j<=N-1; j++) for (int k=N; k>=i; k--) {
			M[j][k] -= M[j][i]*M[i][k];
	}	}
	for (int i=N; i>=0; i--) for (int j=0; j<i; j++) for (int k=N; k>=i; k--) {
		M[j][k] -= M[j][i]*M[i][k];
	}
	return true;
}
