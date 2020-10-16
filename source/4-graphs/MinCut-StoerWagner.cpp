int m[600][600], node[600], inset[600], d[600];

int reduce(int n) {
	memset(inset,0,sizeof(inset));  memset(d,0,sizeof(d));
	inset[node[0]] = 1;
	for (int i=1; i<=n-1; i++) d[node[i]] = m[node[0]][node[i]];
	int ltnode = 0;
	for (int _=1; _<=n-1; _++) {
		int nd = -1;
		for (int i=1; i<=n-1; i++){
			if (inset[node[i]]) continue;
			if (nd ==-1) nd = i;
			if (d[node[i]] > d[node[nd]]) nd = i;
		}
		inset[node[nd]] = 1;
		if (_ == n-1) {
			for (int i=0; i<n; i++) {
				int xxa = node[ltnode], xxb = node[i];
				m[xxa][xxb] += m[node[nd]][node[i]];
				m[xxb][xxa] = m[xxa][xxb];
			}
			int ret = d[node[nd]];  node[nd] = node[n-1];  return ret;
		}
		ltnode = nd;
		for (int i=0; i<n; i++) {
			if (inset[node[i]]) continue;
			d[node[i]] += m[node[nd]][node[i]];
}	}	}
int mincut(int n) {
	for (int i=0; i<n; i++) node[i]= i;
	int res = (1<<30);
	for (int i=n; i>=2; i--) res = min(res, reduce(i));
	return res;
}
int inside_main() {
	for (int N,M; scanf("%d %d", &N, &M) != EOF; ) {
		memset(m, 0, sizeof(m));
		for (int i=0; i<M; i++) {
			int a,b,c; scanf("%d %d %d", &a, &b, &c);  m[a][b] += c;  m[b][a] += c;
		}
		printf("%d\n", mincut(N));
}	}
