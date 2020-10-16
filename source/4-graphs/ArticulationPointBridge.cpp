vector<int> dfs_num, dfs_low, dfs_parent;
int dfs_counter = 0, rootChildren, dfsRoot;

void articulationPoint(int u) {
	dfs_num[u] = dfs_low[u] = dfs_counter++;
	for (auto v: AdjList[u]) {
		if (dfs_num[v] == INF) {
			dfs_parent[v] = u;
			if (u == dfsRoot) rootChildren++;
			articulationPoint(v);
			if(dfs_low[v] >= dfs_num[u]) flag[u] = true; // for Arti. Point
			// bridge Edge(u,v)
			// if(dfs_low[v] > dfs_num[u]) printf("Bridge %d %d\n", u, v);
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		} else if (v != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}	}	}
int inside_main(int V) {
	dfs_counter = 0;  dfs_num.assign(V,INF);  dfs_low.assign(V,0);
	dfs_parent.assign(V,0);  memset(flag,false,sizeof(flag));

	for (int i=0; i<V; i++) if(dfs_num[i] == INF) {
		dfs_root = i;  root_children = 0;  articulationPoint(i);
		flag[i] = (root_children > 1);
}	}
