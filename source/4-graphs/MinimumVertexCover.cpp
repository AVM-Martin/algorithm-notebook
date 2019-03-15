vi AdjList[100010];  int memo[100010][2];

int solve(int idx, int flag, int prev){
	int ans = 0;
	if(memo[idx][flag] != -1) return memo[idx][flag];
	if(AdjList[idx].size()==1 && \
			AdjList[idx][0]==prev)
		return memo[idx][flag] = flag;
	//reccurence
	if(flag == 0){
		ans = 0;
		for(auto j: AdjList[idx]) if(prev != j)
			ans += solve(j,1,idx);
	}
	if(flag == 1){
		ans=1;
		for(auto j: AdjList[idx]) if(prev != j)
			ans += min(solve(AdjList[idx][j],1,idx), \
						solve(AdjList[idx][j],0,idx));
	}
	return memo[idx][flag] = ans;
}
int main(){
	int n; scanf("%d",&n);
	FOR(i,n-1){
		int a,b; scanf("%d %d",&a,&b);
		AdjList[a].pb(b);  AdjList[b].pb(a);
	}
	memset(memo,-1,sizeof(memo));
	int ans = solve(1,0,-1);
	memset(memo,-1,sizeof(memo));
	int ans2 = solve(1,1,-1);
	printf("%d\n", min(ans,ans2));
}