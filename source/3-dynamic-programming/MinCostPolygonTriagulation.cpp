int getCost(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
	return getDist2(a,b) + getDist2(b,c) + getDist2(c,a);
}
int minCutPolygonTriagulation() {
	int res = 0, dp[105][105];
	for (int i=0; i<103; i++) for (int j=0; j<103; j++) dp[i][j] = 0;
	for (int i=0; i<n; i++) res += getDist2(dat[i], dat[(i+1)%n]);
	// DP
	for (int xx=0; xx<n; xx++) for (int i=0,j=xx; j<n; i++,j++) {
		dp[i][j] = (j<i+2) ? 0 : INF;
		for (int k=i+1; k<=j-1; k++) dp[i][j] = min(
			dp[i][j],
			dp[i][k] + dp[k][j] + getCost(dat[i],dat[j],dat[k])
		);
	}
	return (dp[0][n-1] - res) >> 1;
}
