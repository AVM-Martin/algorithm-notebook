// O(nm)   https://arxiv.org/pdf/1208.0396v3.pdf
const int N = 4000+10;
int dp[N][N], from[N][N];
int eq(int a, int b) { return s[(a-1)%n] == t[(b-1)%m]; }
int clcs() {
	for (int i=0; i<=(n<<1); i++) for (int j=0; j<=m; j++) {
		dp[i][j] = from[i][j] = 0;
	}
	for (int i=0; i<=(n<<1); i++) for (int j=0; j<=m; j++) {
		dp[i][j] = 0;
		if(j && dp[i][j-1] > dp[i][j]) dp[i][j] = dp[i][j -1], from[i][j]=0;
		if(i && j && eq(i,j) && dp[i-1][j-1] + 1 > dp[i][j]) {
			dp[i][j] = dp[i-1][j-1]+1, from[i][j]=1;
		}
		if(i && dp[i-1][j] > dp[i][j]) dp[i][j] = dp[i-1][j], from[i][j]=2;
	}
	int ret = 0;
	for (int i=0; i<n; i++) {
		ret = max(ret,dp[i+n][m]);  int x = i+1, y = 0;
		while (y<=m && from[x][y]==0) y++;
		for (; y<=m && x<=n*2; x++) {
			from[x][y] = 0;  dp[x][m]--;
			if (x == n*2) break;
			for (; y<=m; y++) {
				if (from[x+1][y] == 2) break;
				if (y+1 <= m && from[x+1][y+1] == 1) { y++;  break; }
	}	}	}
	return ret << 1;
}
