int m[600][600], node[600], inset[600], d[600];

int reduce(int n){
	memset(inset,0,sizeof(inset));  memset(d,0,sizeof(d));
	inset[node[0]] = 1;
	REP(i,1,n-1) d[node[i]] = m[node[0]][node[i]];
	int ltnode = 0;
	REP(_,1,n-1){
		int nd = -1;
		REP(i,1,n-1){
			if(inset[node[i]]) continue;
			if(nd ==-1) nd = i;
			if(d[node[i]] > d[node[nd]]) nd = i;
		}
		inset[node[nd]] = 1;
		if(_ == n-1){
			FOR(i,n){
				int xxa = node[ltnode], xxb = node[i];
				m[xxa][xxb] += m[node[nd]][node[i]];
				m[xxb][xxa] = m[xxa][xxb];
			}
			int ret = d[node[nd]];  node[nd]=node[n-1];  return ret;
		}
		ltnode = nd;
		FOR(i,n){
			if(inset[node[i]]) continue;
			d[node[i]] += m[node[nd]][node[i]];
}	}	}
int mincut(int n){
	FOR(i,n) node[i]= i;
	int res = (1<<30);
	REV(i,n,2) res = min(res, reduce(i));
	return res;
}
int main(){
	int N, M;
	while(scanf("%d %d", &N, &M) != EOF){
		memset(m, 0, sizeof(m));
		FOR(i,M){
			int a,b,c; scanf("%d %d %d", &a, &b, &c);
			m[a][b] += c;  m[b][a] += c;
		}
		printf("%d\n", mincut(N));
}	}
