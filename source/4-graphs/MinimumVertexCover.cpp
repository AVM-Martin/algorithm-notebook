vector<int> AdjList[100010];  int memo[100010][2];

int solve(int idx, int flag, int prev) {
	int& res = memo[idx][flag];
	if (res != -1) return res;
	if (AdjList[idx].size() == 1 && AdjList[idx][0] == prev) return res = flag;
	// reccurence
	res = (flag==0) ? 0 : 1;
	if (flag == 0) for(auto j: AdjList[idx]) if(prev != j) res += solve(j,1,idx);
	if (flag == 1) for(auto j: AdjList[idx]) if(prev != j){
		int resa = solve(AdjList[idx][j], 1, idx);
		int resb = solve(AdjList[idx][j], 0, idx);
		res += min(resa, resb);
	}
	return res;
}
int inside_main() {
	int n; scanf("%d",&n);
	for (int i=0; i<n-1; i++) {
		int a,b; scanf("%d %d", &a, &b);  AdjList[a].pb(b);  AdjList[b].pb(a);
	}
	memset(memo,-1,sizeof(memo));  int resa = solve(1,0,-1);
	memset(memo,-1,sizeof(memo));  int resb = solve(1,1,-1);
	printf("%d\n", min(resa,resb));
}
