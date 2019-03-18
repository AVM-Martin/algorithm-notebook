// find the alternative shortest path if (u,v) is disconnected
typedef pair<int,pii> tup;  map<pii, int> secondSP;
priority_queue< tup, vector<tup>, greater<tup> > heap;

void doMMG(int s, int t){
	// reset all:   vis[] to 0,   secondSP,   heap
	// list all SP edges in spEdge from s to t with par[]
	// iterate all edges from s to t as avoid
	for(pii avoid: spEdge){
		queue<int> q; /* q.clear(); */ vi seek; seek.clear();
		//do
		q.push(avoid.fi);  seek.pb(avoid.fi);  vis[avoid.fi] = 1;
		while(!q.empty()){
			int u = q.front();  q.pop();
			for(pii v: adjList[u]) if(par[v.fi] == u){
				if(u==avoid.fi && v.fi==avoid.se) continue;
				q.push(v.fi);  seek.pb(v.fi);  vis[v.fi] = 1;
		}	}
		//iterate seek
		for(int u: seek) for(pii v: adjList[u]) if(!vis[v.fi]){
			if(u==avoid.fi && v.fi==avoid.se) continue;
			int _cost = dist[0][u] + v.se + dist[1][v.fi];
			heap.push(mp(_cost, mp(u,v.fi)));
		}
		//remove
		while(!heap.empty() && vis[heap.top().se.se]) heap.pop();
		//push
		secondSP[avoid] = (!heap.empty() ? heap.top().fi : INF);
}	}
// inside int main
//     do dijkstra and save the parent of each node
//     dist[0][u]: s->u,   dist[1][u]: u->t
dijkstra(t,1); // dijkstra with reversed edges
dijkstra(s,0); // dijkstra normally
doMMG(s,t);    // the result is secondSP[] or unnaffected