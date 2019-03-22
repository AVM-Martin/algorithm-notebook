struct Edge{
	int v, flow, c, rev;
	Edge(int _v, int _flow, int _c, int _rev){
		v=_v;  flow=_flow;  c=_c;  rev=_rev;
}	};
class Graph{
	int V, lvl[5005], start[5005];  vector<Edge> adj[5005];
public:
	Graph(int V){ this->V = V; }
	void addEdge(int u, int v, int C){
		Edge a(v, 0,C, adj[v].size());
		Edge b(u, 0,0, adj[u].size());
		adj[u].pb(a);  adj[v].pb(b);
	}
	bool BFS(int s, int t){
		memset(lvl,-1,sizeof(lvl));  lvl[s] = 0;
		queue<int> q;  q.push(s);
		while(!q.empty()){
			int u = q.front();  q.pop();
			for(auto e: adj[u]) if(lvl[e.v] < 0 && e.flow < e.c){
				lvl[e.v] = lvl[u]+1;  q.push(e.v);
		}	}
		return lvl[t] != -1;
	}
	int DFS(int u, int flow, int t, int start[]){
		if(u == t) return flow;
		for(; start[u] < adj[u].size(); start[u]++){
			Edge& e = adj[u][start[u]];
			if(lvl[e.v]==lvl[u]+1 && e.flow<e.c){
				int curr = min(flow, e.c-e.flow);
				int tmp  = DFS(e.v, curr,t, start);
				if(tmp > 0){
					e.flow += tmp;  adj[e.v][e.rev].flow -= tmp;
					return tmp;
		}	}	}
		return 0;
	}
	int dinic(int s, int t){
		int total = 0;
		while(BFS(s,t)){
			memset(start,0,sizeof(start));
			while(int flow = DFS(s,INT_MAX,t,start)) total += flow;
		} return total;
}	};