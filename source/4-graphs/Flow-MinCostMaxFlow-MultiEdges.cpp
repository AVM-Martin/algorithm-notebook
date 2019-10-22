typedef struct { int v, flow, cost, cap; } node;
node parent[MAX_N+1];  vector<node> adj[MAX_N+1];
int dist[MAX_N+1], from[MAX_N+1], v, e;

int augment(int s, int t) {
	bool update;
	for (int i=1; i<=v; i++) dist[i] = INF, from[i] = -1;  dist[s]=0;
	for (int i=1; i<=v-1; i++) { // bellman ford
		update = false;
		for (int j=1; j<=v; j++) for (auto x: adj[j]) if (x.flow < x.cap) {
			int edgeCost = x.cost;
			if (x.flow < 0) edgeCost = -edgeCost;
			if (dist[j] + edgeCost < dist[x.v]) {
				dist[x.v] = dist[j] + edgeCost;
				parent[x.v] = x;  from[x.v] = j;  update = true;
		}	}
		if (!update) break;
	}
	if (dist[t] == INF) return 0;
	int f = INF, pa;  node temp;
	for (int p=t; from[p]!=-1; p=from[p]) {
		pa = from[p];  temp = parent[p];  f = min(f, temp.cap-temp.flow);
	}
	for (int p=t; from[p]!=-1; p=from[p]) {
		pa = from[p];
		for (auto& x: adj[pa]) if (x.v == p && x.cost == parent[p].cost) {
			x.flow += f;  break;
		}
		for (auto& x: adj[p]) if (x.v == pa && x.cost == parent[p].cost) {
			x.flow -= f;  break;
	}	}
	return f * dist[t];
}
void addedge(int v1, int v2, int c, int cap, int flow=0) {
	bool f = true;
	for (auto& x: adj[v1]) if (x.v == v2 && x.cost == c) {
		x.cap += cap;  x.flow += flow;  f = false;  break;
	}
	if (f) adj[v1].pb((node){v2,flow,c,cap});
}
//Add undirected edge a-b dengan cost c, cap 1
addedge(a,b,c,1);  addedge(b,a,c,1);
//directed edge IN(i)->OUT(i) dengan cost a, cap 1
addedge(IN(i),OUT(i),-a,1,0);
addedge(OUT(i),IN(i),a,1,1); //blocking flow
