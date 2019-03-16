struct graph{
	int L, R;
	vector<vi> adj;
	graph(int _L, int _R) : L(_L), R(_R), adj(_L+_R) {}
	void addEdge(int u, int v){ adj[u].pb(v+L);  adj[v+L].pb(u); }
	int maximum_matching(){
		vi level(L), mate(L+R,-1);

		function<bool(void)> levelize = [&]() { // BFS
			queue<int> Q;
			FOR(u,L){
				level[u] = -1;
				if(mate[u] < 0) level[u] = 0, Q.push(u);
			}
			while(!Q.empty()){
				int u = Q.front();  Q.pop();
				for(int w: adj[u]){
					int v = mate[w];
					if(v < 0) return true;
					if(level[v] < 0){
						level[v] = level[u]+1;  Q.push(v);
			}   }   }
			return false;
		};
		function<bool(int)> augment = [&](int u) {
			for(int w: adj[u]){ // DFS
				int v = mate[w];
				if(v<0 || (level[v]>level[u] && augment(v))){
					mate[u] = w;  mate[w] = u;  return true;
			}	}
			return false;
		};
		int match = 0;
		while(levelize()) FOR(u,L)
			if (mate[u]<0 && augment(u)) match++;
		return match;
}	};
int main(){
	int L,R, m, u,v;  scanf("%d %d %d", &L, &R, &m);  graph g(L,R);
	FOR(i,m) scanf("%d %d", &u, &v), g.addEdge(u,v);
	printf("%d\n", g.maximum_matching());
}