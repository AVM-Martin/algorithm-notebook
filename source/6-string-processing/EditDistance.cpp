int dp[MAXN][MAXN];  char s1[MAXN], s2[MAXN];

int main(){
	int len1,len2;
	while(scanf("%d",&len1)!=EOF){
		if(len1>0) scanf("%s",s1);
		scanf("%d",&len2);
		if(len2>0) scanf("%s", s2);
		bool one = (len1==0), two = (len2==0);
		FILL(dp,0);
		dp[0][0] = (s1[0]!=s2[0]);
		REP(i,1,len1-1)dp[i][0] = (s1[i]==s2[0]) ? \
			i : min(i+1,dp[i-1][0]+1);
		REP(i,1,len2-1) dp[0][i] = (s1[0]==s2[i]) ? \
			i : min(i+1,dp[0][i-1]+1);
		REP(i,1,len1-1) REP(j,1,len2-1){
			dp[i][j] = INF;
			if(s1[i] == s2[j])dp[i][j] <?= dp[i-1][j-1];
			dp[i][j] = min(dp[i][j],min(dp[i-1][j]+1, \
				min(dp[i][j-1]+1,dp[i-1][j-1]+1)));
		}
		printf("%d\n",(one^two) ? (max(len1,len2)) : \
			dp[len1-1][len2-1]);
}	}