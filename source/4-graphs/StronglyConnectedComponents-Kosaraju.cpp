// dfs normally, st.push(u) at the end
for (int i=1; i<=n; i++)  dfs(i,0);
// reverse the direction of edges
// dfs from the stack, scc[u] = cnt at the end
for(; !st.empty(); st.pop()) cnt++, dfs(st.top(),1);
