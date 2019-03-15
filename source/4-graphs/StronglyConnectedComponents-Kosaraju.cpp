// dfs normally, st.push(u) at the end
REP(i,1,n) dfs(i,0);
// reverse the direction of edges
// dfs from the stack, scc[u] = cnt at the end
while( !st.empty() ){
	int u=st.top();  st.pop();  cnt++;  dfs(u,1);
}