int cnt = 0;  vi num, low, isSt;  stack<int> st;
int tarjan(int u){
	if(num[u] != -1) return !isSt[u] ? INF : num[u];
	// reccurence
	num[u] = low[u] = ++cnt;  st.push(u);  isSt[u] = 1;
	// move
	for(int v: adjList[u]) low[u] = min(low[u], tarjan(v));
	if(num[u] == low[u]){ // pop
		for(; st.top() != u; st.pop()){
			low[st.top()] = low[u];  isSt[st.top()] = 0;
		} isSt[u] = 0;  st.pop();
	} return low[u];
}