// Given a graph G = (V,E), a matching M in G is a set of pairwise non-adjacent
// edges; that is, no two edges share a common vertex. A maximum matching is a
// matching that contains the largest possible number of edges. There may be
// many maximum matchings. The matching number of a graph is the size of a
// maximum matching. The problem is to find maximum matching of for given graph.
int match[150], parent[150], base[150], V = 4;
bool vis[150], temp[150], blossom[150];
vector<int> vec[150];  queue<int> q;

int LCA(int a, int b) {
	memset(temp,false,sizeof(temp));
	for (; 1; a = parent[match[a]]) {
		a = base[a];  temp[a] = true;
		if (match[a] == -1) break;
	}
	for(; 1; b = parent[match[b]]) {
		b = base[b];
		if (temp[b] == true) return b;
}	}
void markPath(int v, int b, int children) {
	for (; base[v]!=b; v=parent[match[v]]) {
		blossom[base[v]] = blossom[base[match[v]]] = true;
		parent[v] = children;  children = match[v];
}	}
int findPath(int root) {
	memset(vis, false, sizeof(vis));  memset(parent, -1, sizeof(parent));
	for (int a=0; a<V; a++) base[a] = a;
	while (!q.empty()) q.pop();
	q.push(root);  vis[root] = true;
	while (!q.empty()) {
		int pos = q.front();  q.pop();
		for (int nx: vec[pos]) {
			if (base[nx] == base[pos] || match[pos] == nx) continue;
			if (nx == root || match[nx] != -1 && parent[match[nx]] != -1) {
				int curbase = LCA(pos,nx);
				memset(blossom, false, sizeof(blossom));
				markPath(pos, curbase, nx);  markPath(nx, curbase, pos);
				for (int b=0; b<V; b++) if(blossom[base[b]] == true) {
					base[b] = curbase;
					if (vis[b] == false) { vis[b] = true;  q.push(b); }
				}
			} else if(parent[nx] == -1) {
				parent[nx] = pos;
				if (match[nx] == -1) return nx;
				nx = match[nx];  vis[nx] = true;  q.push(nx);
	}	}	}
	return -1;
}
int edmonds() {
	int total = 0;  memset(match,-1,sizeof(match));
	for (int a=0; a<V; a++) if(match[a] == -1) {
		int nx = findPath(a);
		while (nx != -1) {
			int pnx = parent[nx];  int ppnx = match[pnx];
			match[nx] = pnx;  match[pnx] = nx;  nx = ppnx;
	}	}
	for (int a=0; a<V; a++) if (match[a] != -1) total++;
	return total >> 1;
}
