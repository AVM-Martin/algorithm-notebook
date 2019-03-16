vi dfs_num, dfs_low, dfs_parent;
int dfs_counter = 0, rootChildren, dfs_root;

void articulationPoint(int u){
	dfs_num[u] = dfs_low[u] = dfs_counter++;
	for(auto v: AdjList[u]){
		if(dfs_num[v] == INF){
			dfs_parent[v] = u;
			if(u == dfsRoot)rootChildren++;
			articulationPoint(v);
			// Arti. Point
			if(dfs_low[v] >= dfs_num[u]) flag[u] = true;
			// bridge Edge(u,v)
			if(dfs_low[v] > dfs_num[u])
				dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		} else if(v != parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}	}	}
//inside int main
dfs_counter = 0;  dfs_num.assign(V,INF);
dfs_low.assign(V,0);  dfs_parent(V,0);
memset(flag,false,sizeof(flag));
FOR(i,V) if(dfs_num[i] == INF){
	dfs_root = i;  rootChildren = 0;
	articulationPoint(i);
	flag[i] = (rootChildren>1);
}