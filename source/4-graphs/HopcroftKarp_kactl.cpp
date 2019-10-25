// Source: https://github.com/kth-competitive-programming/kactl/
// Desc  : Find a maximum matching in a bipartite graph.
// Status: Tested on oldkattis.adkbipmatch and SPOJ:MATCHING
// Usage : vi ba(m, -1); hopcroftKarp(g, ba);
// Time  : O(E sqrt(V))
typedef vector<int> vi;  typedef vector< vi > vvi;

bool dfs(int a, int layer, const vvi& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != layer) return 0;
	A[a] = -1;
	for (auto& b: g[a]) if (B[b] == layer + 1) {
		B[b] = -1;
		if (btoa[b] == -1 || dfs(btoa[b], layer + 1, g, btoa, A, B)) {
			return btoa[b] = a, 1;
	}	}
	return 0;
}
int hopcroftKarp(const vvi& g, vi& btoa) {
	int res = 0;  vi A((int)g.size()), B((int)btoa.size()), cur, next;
	while (1) {
		fill(all(A), 0);  fill(all(B), 0); // AVM: memset (?)
		// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (auto& a: btoa) if(a != -1) A[a] = -1;
		for (int a=0; a<(int)g.size(); a++) if(A[a] == 0) cur.push_back(a);
		// Find all layers using bfs.
		for (int lay=1; ; lay++) {
			bool islast = 0;  next.clear();
			for(auto& a: cur) for(auto& b: g[a]) {
				if (btoa[b] == -1) B[b] = lay, islast = 1;
				else if (btoa[b] != a && B[b] == 0) {
					B[b] = lay, next.push_back(btoa[b]);
			}	}
			if (islast) break;
			if (next.empty()) return res;
			for (auto& a: next) A[a] = lay;
			cur.swap(next);
		}
		// Use DFS to scan for augmenting paths.
		for (int a=0; a<(int)g.size(); a++) res += dfs(a, 0, g, btoa, A, B);
}	}
