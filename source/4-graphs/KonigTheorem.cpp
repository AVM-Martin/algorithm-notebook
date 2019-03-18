vi adj[1005];
int matchL[1005], matchR[1005], visitL[1005], visitR[1005];

int aug(int u){
	visitL[u] = true;
	for(auto v: adj[u]) if(!visitR[v]){
		visitR[v] = true;
		if(matchR[v] == -1 || aug(matchR[v])){
			matchL[u] = v;  matchR[v] = u;  return 1;
	}	}
	return 0;
}
//inside int main
FOR(i,1003)
	matchL[i]=matchR[i]=-1, visitL[i]=visitR[i]=0, adj[i].clear();
int n,m,k, a,b; scanf("%d %d %d", &n, &m, &k);
FOR(i,k) scanf("%d %d", &a, &b),0 adj[a].pb(b);
int mcbm = 0;
REP(i,1,n) memset(visitR, 0, sizeof(visitR)), mcbm += aug(i);
// recover
memset(visitL,0,sizeof(visitL));  memset(visitR,0,sizeof(visitR));
REP(i,1,n) if(matchL[i]==-1) aug(i);
REP(i,1,n) if(!visitL[i]) printf(" r%d",i); // pick
REP(i,1,m) if(visitR[i]) printf(" c%d",i);  // pick