// Every edge is visited exactly once
int N, M, d[250], di[250], m[205][205], pre[205],vis[205];

int flow(int f, int si){
	memset(vis,0,sizeof(vis));  memset(pre,-1,sizeof(pre));
	queue<int> q;  q.push(f);
	while(!q.empty()){
		int now = q.front();  q.pop();
		if(vis[now] == 2) continue;
		vis[now] = 2;
		if(now == si) break;
		FOR(next,N+1){
			if(vis[next]) continue;
			if(m[now][next] > 0)
				vis[next]=1, pre[next]=now, q.push(next);
	}	}
	int ret = (1<<30);
	for(int nt=si; pre[nt]!=-1; nt=pre[nt])
		ret = min(ret, m[pre[nt]][nt]);
	if(ret >= (1<<30)) return 0;
	for(int nt=si; pre[nt]!=-1; nt=pre[nt])
		m[pre[nt]][nt] -= ret, m[nt][pre[nt]] += ret;
	return ret;
}
int solve(){
	scanf("%d %d", &N, &M);
	memset(d,0,sizeof(d));  memset(m,0,sizeof(m));
	FOR(i,M){
		int a,b,c; scanf("%d %d %d", &a, &b, &c);
		d[a]++;  d[b]--;
		if(!c) m[a][b]++;
	}
	int can = 1;
	for(int i=1; can && i<=N; i++){
		int x = abs(d[i]);  d[i]>>=1;
		if(x&1) can=0;
	}
	if(can){
		int tflow = 0;
		REP(i,1,N){
			if(d[i] <  0) m[i][N+1] = -d[i];
			if(d[i]  > 0) m[0][i] = d[i], tflow += d[i];
		}
		int tans, ans = 0;
		while((tans=flow(0,N+1)) > 0) ans += tans;
		can &= (ans == tflow);
	}
	puts(can ? "possible" : "impossible");
}
