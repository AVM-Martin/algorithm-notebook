typedef struct{ int v, flow, cost, cap; } node;
node parent[MAX_N+1];  vector<node> adj[MAX_N+1];
int dist[MAX_N+1], from[MAX_N+1], v, e;

int augment(int s,int t){
	bool update;
	REP(i,1,v)dist[i] = INF, from[i] = -1;
	dist[s]=0;
	REP(i,1,v-1){ //bellman ford
		update = false;
		REP(j,1,v) FOR(k,adj[j].size())
		if(adj[j][k].flow < adj[j][k].cap){
			int edgeCost = adj[j][k].cost;
			if(adj[j][k].flow <0) edgeCost = -edgeCost;
			if(dist[adj[j][k].v] > dist[j]+edgeCost){
				dist[adj[j][k].v] = dist[j]+ edgeCost;
				parent[adj[j][k].v] = adj[j][k];
				from[adj[j][k].v] = j;
				update = true;
		}	} if(!update)break;
	}
	if(dist[t]==INF)return 0;
	int p = t, f = INF, pa;  node temp;
	for(; from[p]!=-1; p=from[p]){
		pa = from[p];  temp = parent[p];
		f = min(f,temp.cap-temp.flow);
	}
	p = t;
	for(; from[p]!=-1; p=from[p]){
		pa = from[p];
		FOR(i,adj[pa].size()){
			if(adj[pa][i].v == p && \
					adj[pa][i].cost == parent[p].cost){
				adj[pa][i].flow += f; break;
		}	}
		FOR(i,adj[p].size()){
			if(adj[p][i].v == pa && \
					adj[p][i].cost == parent[p].cost){
				adj[p][i].flow -= f; break;
	}	}	}
	return f*dist[t];
}
void addedge(int v1, int v2, int c, int cap, \
		int flow=0){
	bool f = true;
	FOR(i,adj[v1].size())
		if(adj[v1][i].v==v2 && adj[v1][i].cost==c){
			adj[v1][i].cap += cap;
			adj[v1][i].flow += flow;
			f = false;  break;
		}
	if(f) adj[v1].pb((node){v2,flow,c,cap});
}
//Add undirected edge a-b dengan cost c, cap 1
addedge(a,b,c,1);  addedge(b,a,c,1);
//directed edge IN(i)->OUT(i) dengan cost a, cap 1
addedge(IN(i),OUT(i),-a,1,0);
addedge(OUT(i),IN(i),a,1,1); //blocking flow