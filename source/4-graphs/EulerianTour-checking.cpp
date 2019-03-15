// Every edge is visited exactly once
int N, M, d[250], di[250];
int m[205][205], pre[205],vis[205];

int flow(int f, int si){
	queue<int> q;  q.push(f);
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	while(!q.empty()){
		int now = q.front();  q.pop();
		if(vis[now] == 2)continue;
		vis[now] = 2;
		if(now == si)break;
		FOR(i,N+1){
			int next = i;
			if(vis[next])continue;
			if(m[now][next]>0)
				vis[next]=1, pre[next]=now, q.push(next);
	}	}
	int nt = si, ret = (1<<30);
	while(pre[nt] != -1){
		int bf = pre[nt];
		ret = min(ret,m[bf][nt]);  nt = bf;
	}
	if(ret >= (1<<30))return 0;
	nt = si;
	while(pre[nt] != -1){
		int bf = pre[nt];
		m[bf][nt] -= ret;  m[nt][bf] += ret;  nt = bf;
	}
	return ret;
}
int main(){
	int ntc;
	scanf("%d",&ntc);
	while(ntc--){
		scanf("%d%d",&N,&M);
		memset(d,0,sizeof(d));
		memset(m,0,sizeof(m));
		FOR(i,M){
			int a,b,c; scanf("%d%d%d",&a,&b,&c);
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
				if(d[i]<0)m[i][N+1] = -d[i];
				else if(d[i]>0)m[0][i]=d[i], tflow+=d[i];
			}
			int tans, ans = 0;
			while((tans=flow(0,N+1)) > 0)ans += tans;
			can = can && (ans == tflow);
		}
		puts(can ? "possible" : "impossible");
}	}