// SPOJ BREAKING STRINGS
// Reccurence : dp[i][j] = min{ dp[i][k]+dp[k][j] } + C[i][j]
// Condition  : i < k < j and A[i,j-1] <= A[i,j] <= A[i+1,j]
// from O(n^3) become O(n^2)
int arr[1005], dp[1005][1005], mid[1005][1005];
// inside int main
int n,m; scanf("%d %d", &n, &m);
REP(i,1,m) scanf("%d", &arr[i]);  arr[0]=0;  arr[m+1]=n;
REV(i,m+1,0) REP(j,0,m+1) if(i <= j){
	if(j-i < 2){ dp[i][j] = 0;  mid[i][j] = i;  continue; }
	int optL = mid[i][j-1], optR = mid[i+1][j];
	dp[i][j] = INF;
	REP(k,optL,optR){
		int tmp = dp[i][k] + dp[k][j] + arr[j]-arr[i];
		if(tmp < dp[i][j]) dp[i][j] = tmp, mid[i][j] = k;
}	}
printf("%d\n",dp[0][m+1]);
