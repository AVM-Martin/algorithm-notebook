vector<int> adj[1005];
int matchL[1005], matchR[1005], visitL[1005], visitR[1005];

int aug(int u) {
	visitL[u] = true;
	for (auto v: adj[u]) if (!visitR[v]) {
		visitR[v] = true;
		if (matchR[v] == -1 || aug(matchR[v])) {
			matchL[u] = v;  matchR[v] = u;  return 1;
	}	}
	return 0;
}
// inside main()
for (int i=0; i<1003; i++) {
	matchL[i] = matchR[i] = -1, visitL[i] = visitR[i] = 0, adj[i].clear();
}
int n,m,k, a,b;  scanf("%d %d %d", &n, &m, &k);
for (int i=0; i<k; i++) scanf("%d %d", &a, &b), adj[a].pb(b);
int mcbm = 0;
for (int i=1; i<=n; i++) memset(visitR, 0, sizeof(visitR)), mcbm += aug(i);
// recover
memset(visitL, 0, sizeof(visitL));  memset(visitR, 0, sizeof(visitR));
for (int i=1; i<=n; i++) if (matchL[i] == -1) aug(i);
for (int i=1; i<=n; i++) if (!visitL[i]) printf(" r%d",i);  // pick
for (int i=1; i<=m; i++) if ( visitR[i]) printf(" c%d",i);  // pick
