vector< vector<int> > adj;  vector<int> parent;

void dfs(int u, int _parent) {
	for (int v : adj[u]) if (v != _parent) dfs(v, parent[v] = u);
}

vector<int> pruefer_code() {
	int n = adj.size();  parent.resize(n);
	parent[n-1] = -1;  dfs(n-1, -1);
	int ptr = -1;  vector<int> degree(n);

	for (int i=0; i<n; i++) {
		if ((degree[i] = adj[i].size()) == 1 && ptr == -1) ptr = i;
	}

	vector<int> code(n-2);  int leaf = ptr;
	for (int i=0; i<n-2; i++) {
		int next = code[i] = parent[leaf];
		if (--degree[next] == 1 && next < ptr) {
			leaf = next;
		} else {
			ptr++;  while (degree[ptr] != 1) ptr++;
			leaf = ptr;
	}	}
	return code;
}

vector< pair<int, int> > pruefer_decode(const vector<int>& code) {
	int n = (int)code.size() + 2;  vector<int> degree(n, 1);
	for (int i : code) degree[i]++;

	int ptr = 0;  while (degree[ptr] != 1) ptr++;
	int leaf = ptr;

	vector< pair<int, int> > edges;
	for (int v : code) {
		edges.push_back(make_pair(leaf, v));
		if (--degree[v] == 1 && v < ptr) {
			leaf = v;
		} else {
			ptr++;  while (degree[ptr] != 1) ptr++;
			leaf = ptr;
	}	}
	edges.push_back(make_pair(leaf, n-1));
	return edges;
}
