void add(int u, int p, int val){
	cnt[col[u]] += val;
	for(auto v: adjList[u]){
		if(v==p || big[v]) continue;
		add(v,u,val);
	}
}
void dsu(int u, int p, bool keep){
	int maks = -1, bigChild = -1;
	for(auto v: adjList[u]){
		if(v == p) continue;
		if(maks< sz[v]) maks = sz[v], bigChild = v;
	}
	for(auto v: adjList[u]){
		if(v == p || v == bigChild) continue;
		dsu(v,u,0);
	}
	if(bigChild != -1){
		dsu(bigChild,u,1);
		big[bigChild] = true;
	}
	add(u,p,1);
	if(bigChild != -1) big[bigChild] = false;
	if(keep == 0) add(u,p,-1);
}