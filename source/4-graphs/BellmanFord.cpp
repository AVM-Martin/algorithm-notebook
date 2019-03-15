int bellmanFord(int s){
	int i, j;  FOR(i,n)d[i]= INF;  d[s]=0;
	FOR(i,n-1) FOR(j,e)
		if(d[edge[j].v] > d[edge[j].u]+edge[j].w)
			d[edge[j].v] = d[edge[j].u]+edge[j].w;
	FOR(j,e)
		if(d[edges[j].u] + edges[j].w < d[edges[j].v])
			return 0;
	return 1;
}