int dp[MAXN][MAXN];  char s1[MAXN], s2[MAXN];

// inside main()
int len1;  scanf("%d", &len1);  if (len1 > 0) scanf("%s", s1);
int len2;  scanf("%d", &len2);  if (len2 > 0) scanf("%s", s2);
bool one = (len1 == 0), two = (len2 == 0);
memset(dp, 0, sizeof(dp));  dp[0][0] = (s1[0] != s2[0]);
for (int i=1; i<=len1-1; i++) {
	dp[i][0] = (s1[i] == s2[0]) ? i : min(i+1, dp[i-1][0]+1);
}
for (int i=1; i<=len2-1; i++) {
	dp[0][i] = (s1[0] == s2[i]) ? i : min(i+1, dp[0][i-1]+1);
}
for (int i=1; i<=len1-1; i++) for (int j=1; j<=len2-1; j++) {
	dp[i][j] = INF;
	if (s1[i] == s2[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
	dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
	dp[i][j] = min(dp[i][j], min(dp[i-1][j]+1,dp[i][j-1]+1));
}
printf("%d\n", (one^two) ? (max(len1,len2)) : dp[len1-1][len2-1]);
