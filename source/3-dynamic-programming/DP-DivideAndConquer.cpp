// dp[i][j] = min(dp[i-1][k] + C[k][j]) for (k<j)
// A[i][j] <= A[i][j+1]
// O(knlogn)

void solve(int k, int l, int r, int L , int R){
	if(l > r)return;
	int mid = (l+r)/2, opt = -1;
	REP(i,L,min(R,mid)){
		ll tmp = dp[k-1][i]+cost[i+1][mid];
		if(tmp < dp[k][mid])dp[k][mid] = tmp, opt = i;
	}
	solve(k,l,mid-1,L,opt);  solve(k,mid+1,r,opt,R);
}
int main(){
	// init array of dp to infinity
	// init array dp[1][i] = to cost[1][i]
	REP(i,2,k)solve(i,1,n,1,n);
}