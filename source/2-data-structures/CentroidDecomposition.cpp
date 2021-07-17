vector<int> adj[N+5], nadj[N+5];  bool done[N+5];  int subsz[N+5], dep[N+5];
int dfs(int u, int bef = -1); // calc subsz[]
int find_centroid(int u, int bef, int sz){
	for(auto v: adj[u]) if (v.first != bef && done[v.first] == 0) {
		if (subsz[v.first] > (sz >> 1)) return find_centroid(v.first, u, sz);
	} return u;
}
int make_centroid(int u) {
	dfs(u);  if (subsz[u] == 1) return u;
	int cen = find_centroid(u,-1,subsz[u]);  done[cen] = 1;
	for (auto v: adj[cen]) if (done[v.first] == 0) {
		nadj[cen].push_back( make_centroid(v.first) );
	} return cen;
}
