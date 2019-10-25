int tarjan(int u, int p) {
	if (num[u] != -1) return num[u];
	num[u] = low[u] = ++cnt;  st.push(u);
	for (int v : G[u]) if (v != p) {
		if (num[v] != -1) low[u] = min(low[u], num[v]);
		else {
			low[u] = min(low[u], tarjan(v,u));
			if (num[u] <= low[v]) {
				scc[idx].push_back(u);
				while (!st.empty() && st.top() != v) {
					scc[idx].push_back(st.top());  st.pop();
				}
				scc[idx].push_back(st.top());  st.pop();  idx++;
	}	}	}
	return low[u];
}
