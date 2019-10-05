vi topoSortKahn(){
	// get all in-degrees
	vi in_degree(V,0);
	FOR(u,V) for(int x: adj[u]) in_degree[x]++;
	// queue all indegree == 0
	queue<int> q;
	FOR(i,v) if(in_degree[i] == 0) q.push(i);
	vi res;  res.clear();
	while(!q.empty()){
		int u = q.front();  q.pop();  res.pb(u);
		for(int x: adj[u]) if(--in_degree[x] == 0) q.push(x);
	}
	// Check if there was a cycle
	if((int)res.size() != V){ res.clear(); puts("Cycle!"); }
	return res;
}
