int bellmanFord(int s) {
	for (int i=0; i<n; i++) d[i] = INF;
	d[s] = 0;
	for (int i=0; i<n-1; i++) for (int j=0; j<e; j++) {
		if (d[edge[j].u] + edge[j].w < d[edge[j].v]) {
			d[edge[j].v] = d[edge[j].u] + edge[j].w;
		}
	}
	for (int j=0; j<e; j++) {
		if (d[edges[j].u] + edges[j].w < d[edges[j].v]) return 0;
	}
	return 1;
}
