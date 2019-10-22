// Eulerian on Directed Graph
stack<int> path;  vector<int> euler;
inline void hierholzer() {
	path.push(0);  int cur = 0;
	while (!path.empty()) {
		if (!adj[cur].empty()) {
			path.push(cur);  int next = adj[cur].back();
			adj[cur].pop_back();  cur = next;
		} else {
			euler.push_back(cur);  cur = path.top();  path.pop();
	}	}
	reverse(euler.begin(), euler.end());
}
