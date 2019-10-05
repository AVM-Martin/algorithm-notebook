struct graph{
	int n;
	struct edge{ int src, dst, rev; };
	vector< vector<edge> > adj;
	graph() : n(0) {}
	//graph(int n) : n(n), adj(n) {}
	void addEdge(int src, int dst){
		n = max(n,max(src,dst)+1);
		if(adj.size() < n) adj.resize(n);
		adj[src].pb({src, dst, (int)adj[dst].size()  });
		adj[dst].pb({dst, src, (int)adj[src].size()-1});
	}
	// destructive
	vi path;
	void visit(int u){
		while(!adj[u].empty()){
			auto e = adj[u].back();  adj[u].pob();
			if(e.src >= 0){
				adj[e.dst][e.rev].src = -1;  visit(e.dst);
		}	}
		path.pb(u);
	}
	vi eulerianPath(){
		int m = 0, s = -1;
		FOR(u,n){
			m += adj[u].size();
			if(adj[u].size()%2 == 1) s = u;
		}
		path.clear();  if(s >= 0) visit(s);
		if(path.size() != m/2+1) return {};
		return path;
	}
	vi eulerianTour(){
		int m = 0, s = 0;
		FOR(u,n){
			m += adj[u].size();
			if(adj[u].size() > 0) s = u;
		}
		path.clear();  visit(s);
		if(path.size() != m/2+1 || path[0]!=path.back()) return {};
		return path;
}	};
int solve(){
	int m, s,t; scanf("%d",&m);  graph g;
	FOR(i,m) scanf("%d %d", &s, &t), g.addEdge(s-1, t-1);
	auto path = g.eulerianTour();
	if(path.empty()) printf("may be lost\n");
	else FOR(i,(int)path.size()-1){
		printf("%d %d\n", path[i]+1, path[i+1]+1);
}	}
