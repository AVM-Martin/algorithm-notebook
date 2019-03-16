// SPOJ BREAKING STRINGS
// Reccurence : dp[i][j] = min{ dp[i][k]+dp[k][j] } + C[i][j]
// Condition  : i < k < j and A[i,j-1] <= A[i,j] <= A[i+1,j]
// from O(n^3) become O(n^2)
ll n, dp[1005][1005], f[1005];
int m, mid[1005][1005];

int main(){
	while(scanf("%lld %d",&n,&m) == 2){
		REP(i,1,m) scanf("%lld", &f[i]);  f[0] = 0;  f[m+1] = n;
		FOR(i,m+2) FOR(j,m+2) dp[i][j] = 1e18, mid[i][j] = i;
		FOR(s,m+2) FOR(l,m-s+2){
			int r = l+s;
			if(s < 2){ dp[l][r] = 0;  mid[l][r] = l;  continue; }
			int mleft = mid[l][r-1], mright = mid[l+1][r];
			dp[l][r] = 1e18;
			REP(i,mleft,mright){
				ll tmp = dp[l][i] + dp[i][r] + f[r]-f[l];
				if(tmp < dp[l][r]) dp[l][r] = tmp, mid[l][r] = i;
		}	}
		printf("%lld\n", dp[0][m+1]);
}	}