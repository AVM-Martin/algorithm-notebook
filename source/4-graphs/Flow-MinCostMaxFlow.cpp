bool bellman(){
	FOR(i,260) dist[i]=INF, p[i]=-1;  dist[src] = 0; bool alter;
	FOR(k,259){
		alter = false;
		FOR(i,260) for(auto v: adj[i])
			if(dist[i]+cost[i][v] < dist[v] && res[i][v])
				alter = true, dist[v] = dist[i]+cost[i][v], p[v] = i;
		if(!alter) break;
	}
	return (dist[sink] != INF);
}
void augment(int u, int minEdge){
	if(src == u){ flow = minEdge; return; }
	if(p[u] != -1){
		augment(p[u], min(minEdge,res[p[u]][u]));
		res[p[u]][u] -= flow;
		res[u][p[u]] += flow;
		costPerFlow += cost[p[u]][u];
}	}
// inside int main
// construct graph
// make bidirectional edge from src to i
cost[src][i]  = x;  cost[i][src]  = -x;  res[src][i]  = y;
// make bidirectional edge from i to sink
cost[i][sink] = x;  cost[sink[i]] = -x;  res[i][sink] = y;
// do it
while(bellman()){
	flow = 0;  augment(sink,INF);
	if(flow == 0) break;
	mf += flow;  totCost += costPerFlow;
}
