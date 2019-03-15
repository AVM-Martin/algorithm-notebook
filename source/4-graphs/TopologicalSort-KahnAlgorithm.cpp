vi topoSortKahn(){
	// get all in-degrees
	vi in_degree(V,0);
	FOR(u,V) for(int x: adj[u]) in_degree[x]++;
	queue<int> q;
	// queue all indegree == 0
	FOR(i,v) if(in_degree[i] == 0) q.push(i);
	int cnt = 0;  vi res;
	while(!q.empty()){
		int u = q.front();  q.pop();  res.pb(u);
		for(int x: adj[u])
			if(--in_degree[x] == 0)q.push(x);
		cnt++;
	}
	// Check if there was a cycle
	if(cnt != V){ res.clear(); puts("Cycle!"); }
	return res;
}