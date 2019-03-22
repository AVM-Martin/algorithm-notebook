// Reccurence : dp[i][j] = min{ dp[i-1][k] + C[k][j] }
// Condition  : k < j and A[i][j] <= A[i][j+1]
// from O(kn^2) become O(kn log n)
void solve(int group, int lf, int rg, int optL , int optR){
	if(lf > rg) return;
	int mid = (lf+rg)/2, opt = -1, batas = min(optR,mid);
	REP(i,optL,batas){
		ll tmp = dp[group-1][i] + cost[i+1][mid];
		if(tmp < dp[group][mid]) dp[group][mid] = tmp, opt = i;
	}
	solve(group,lf,mid-1,optL,opt);  solve(group,mid+1,rg,opt,optR);
}
int main(){
	// init array of dp to infinity
	// init array dp[1][i] = to cost[1][i]
	REP(i,2,k) solve(i,1,n,1,n);
}
