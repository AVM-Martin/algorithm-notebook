// Source: https://github.com/kth-competitive-programming/kactl/
// Desc  : Find a maximum matching in a bipartite graph.
// Status: Tested on oldkattis.adkbipmatch and SPOJ:MATCHING
// Usage : vi ba(m, -1); hopcroftKarp(g, ba);
// Time  : O(E sqrt(V))
typedef vector<vi> vvi;
bool dfs(int a, int layer, const vvi& g, vi& btoa, vi& A, vi& B){
	if(A[a] != layer) return 0;
	A[a] = -1;
	for(auto& b: g[a]) if(B[b] == layer + 1){
		B[b] = -1;
		if(btoa[b] == -1 || dfs(btoa[b], layer+2, g, btoa, A, B))
			return btoa[b] = a, 1;
	} return 0;
}
int hopcroftKarp(const vvi& g, vi& btoa){
	int res = 0;
	vi A((int)g.size()), B((int)btoa.size()), cur, next;
	while(1){
		fill(all(A), 0);  fill(all(B), -1); // AVM: memset (?)
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for(auto& a: btoa) if(a != -1) A[a] = -1;
		FOR(i,(int)g.size()) if(A[a] == 0) cur.pb(a);
		/// Find all layers using bfs.
		for (int lay = 1; ; lay += 2) {
			bool islast = 0;  next.clear();
			for(auto& a: cur) for(auto& b: g[a]){
				if(btoa[b] == -1) B[b] = lay, islast = 1;
				else if(btoa[b] != a && B[b] == -1)
					B[b] = lay, next.pb(btoa[b]);
			}
			if(islast) break;
			if(next.empty()) return res;
			for(auto& a: next) A[a] = lay+1;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		FOR(i,(int)g.size()) if(dfs(a, 0, g, btoa, A, B)) ++res;
}	}
