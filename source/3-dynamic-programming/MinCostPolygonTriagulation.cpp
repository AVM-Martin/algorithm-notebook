int getCost(pii a, pii b, pii c){
	return getDist2(a,b) +getDist2(b,c) + getDist2(c,a);
}
int minCutPolygonTriagulation(){
	int res=0, dp[105][105];
	FOR(i,103) FOR(j,103) dp[i][j] = 0;
	FOR(i,n) res += getDist2(dat[i],dat[(i+1)%n]);
	//DP
	FOR(xx,n) for(int i=0,j=xx; j<n; i++,j++){
		dp[i][j] = (j<i+2) ? 0 : INF;
		REP(k,i+1,j-1) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j] + getCost(dat[i],dat[j],dat[k]) );
	}
	return (dp[0][n-1]-res) >> 1;
}
