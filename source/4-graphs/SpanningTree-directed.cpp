int con[MAXN][MAXN], in[MAXN];
int vis[MAXN], active[MAXN], n;
//vis state: 0:unvisited, 1:visited, 2:cycle, 3:active
int cycle(int idx, int& res) {
	if (vis[idx] == 0) {
		vis[idx] = 3;
		if (in[idx] == -1) vis[idx] = 1;
		else vis[idx] = cycle(in[idx],res);
		return vis[idx];
	}
	if (vis[idx] != 3) return vis[idx];
	//vis[idx] == 3
	set<int> pseudoNodes;  int minCycle = INF;
	for (int j=idx; ; j=in[j]) {
		pseudoNodes.insert(j);
		minCycle = min(minCycle, con[ in[j] ][j]);
		if (in[j] == idx) break;
	}
	int minCost = INF, bestParent;
	for (auto j: pseudoNodes) for (int i=0; i<n; i++) {
		if (active[i] && con[i][j] != -1 && !pseudoNodes.count(i)) {
			if (minCost > con[i][j]-con[in[j]][j]) {
				minCost = con[i][j]-con[in[j]][j];
				bestParent = i;
			}
			con[i][j] -= con[in[j]][j]-minCycle;
	}	}
	res += minCost;  in[idx] = bestParent;
	for (auto j: pseudoNodes) {
		for (int i=0; i<n; i++) if (active[i] && i != idx && con[i][j] != -1) {
			if (con[i][idx] == -1 || con[i][idx] > con[i][j]) {
				con[i][idx] = con[i][j];
		}	}
		for (int i=0; i<n; i++) if(active[i] && i != idx && con[j][i] != -1) {
			if (in[i] == j) in[i] = idx;
			if (con[idx][i] == -1 || con[idx][i] > con[j][i]) {
				con[idx][i]= con[j][i];
		}	}
		if (j != idx) active[j] = false;
	} return vis[idx] = 2;
}
int dmst(int root) {
	int res = 0;  in[root] = -1;  for (int i=0; i<n; i++) con[i][root] = -1;
	for (int i=0; i<n; i++) if (i != root) {
		int minCost = INF;
		for (int j=0; j<n; j++) if (con[j][i] != -1 && con[j][i] < minCost) {
			minCost = con[j][i], in[i] = j;
		}
		res += minCost;
	}
	memset(active, 1, sizeof(active));
	while (1) {
		memset(vis, 0, sizeof(vis));  bool hasCycle = cycle(root,res) == 2;
		for (int i=0; i<n; i++) if (active[i] & !vis[i]) {
			hasCycle |= cycle(i,res) == 2;
		}
		if (!hasCycle) return res;
}	}
int dfs(int idx) {
	if (vis[idx]) return 0;
	int ret = 1;  vis[idx] = true;
	for (int i=0; i<n; i++) if (con[idx][i] != -1) ret += dfs(i);
	return ret;
}
bool connected(int root) {
	memset(vis,0,sizeof(vis));  return dfs(root) == n;
}
int solve(int tc) {
	printf("Case #%d: ", tc);
	int m, u,v,w; scanf("%d %d", &n, &m);
	memset(con, -1, sizeof(con));
	for (int i=0; i<m; i++) scanf("%d %d %d", &u, &v, &w), con[u][v] = w;
	if (!connected(0)) puts("Possums!");
	else printf("%d\n", dmst(0));
}
