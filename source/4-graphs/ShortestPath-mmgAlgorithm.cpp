// find the alternative shortest path if (u,v) is disconnected
typedef pair<int,int> pii;  typedef pair<int,pii> tup;  map<pii, int> secondSP;
priority_queue< tup, vector<tup>, greater<tup> > heap;

void doMMG(int s, int t) {
	// reset all:   vis[] to 0,   secondSP,   heap
	// list all SP edges in spEdge from s to t with par[]
	// iterate all edges from s to t as avoid
	for (pii avoid: spEdge) {
		queue<int> q; /* q.clear(); */ vector<int> seek; seek.clear();
		//do
		q.push(avoid.first);  seek.pb(avoid.first);  vis[avoid.first] = 1;
		while (!q.empty()) {
			int u = q.front();  q.pop();
			for (pii v: adjList[u]) if (par[v.first] == u) {
				if (u == avoid.first && v.first == avoid.second) continue;
				q.push(v.first);  seek.pb(v.first);  vis[v.first] = 1;
		}	}
		//iterate seek
		for (int u: seek) for (pii v: adjList[u]) if (!vis[v.first]) {
			if (u == avoid.first && v.first == avoid.second) continue;
			int _cost = dist[0][u] + v.second + dist[1][v.first];
			heap.push(mp(_cost, mp(u,v.first)));
		}
		//remove
		while (!heap.empty() && vis[heap.top().second.second]) heap.pop();
		//push
		secondSP[avoid] = (!heap.empty() ? heap.top().first : INF);
}	}
int inside_main() {
	// do dijkstra and save the parent of each node
	// dist[0][u]: s->u,   dist[1][u]: u->t
	dijkstra(t,1); // dijkstra with reversed edges
	dijkstra(s,0); // dijkstra normally
	doMMG(s,t);    // the result is secondSP[] or unnaffected
}
