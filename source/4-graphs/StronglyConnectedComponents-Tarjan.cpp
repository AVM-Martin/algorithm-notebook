int cnt = 0;  vi num, low, isSt;  stack<int> st;

int tarjan(int u){
	if(num[u] != -1) return !isSt[u] ? INF : num[u];
	// reccurence
	num[u] = low[u] = ++cnt;
	st.push(u);  isSt[u] = 1;
	for(int v: adjList[u]) // move
		low[u] = min(low[u], tarjan(v));
	if(num[u] == low[u]){ // pop, if root
		while(st.top() != u){
			low[st.top()] = low[u];
			isSt[st.top()] = 0;  st.pop();
		}
		isSt[u] = 0;  st.pop();
	}
	return low[u];
}