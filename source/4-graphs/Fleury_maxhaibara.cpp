// Eulerian on Undirected Graph
// To find eulerian path simply make a dummy node for the starting and ending
// vertex. I.E start DFS from start point or end point
bool E[1010][1010];  vector< pair<int,int> > euler;
int vis[1010];  int color = 0;
inline void setEdge(int cur, int next, bool val) {
	E[cur][next] = E[next][cur] = val;
}
int DFS(int cur) {
	vis[cur] = color; int ret=1;
	for (auto next: adj[cur]) {
		if (E[cur][next] && vis[next] != color) ret += DFS(next);
	}
	return ret;
}
inline bool valid(int cur, int next) {
	int cnt = 0;  for (int data: adj[cur]) if (E[cur][data]) cnt++;
	if (cnt == 1) return true;
	color++;  int cnt1 = DFS(cur);  setEdge(cur, next, false);
	color++;  int cnt2 = DFS(cur);  setEdge(cur, next, true);
	return cnt1 <= cnt2;
}
void fleury(int cur) { // start from odd degree
	for (int next: adj[cur]) {
		if (E[cur][next] && valid(cur,next)) {
			euler.push_back({cur,next});  setEdge(cur, next, false);
			fleury(next);
	}	}
	ans.pb(cur); // from ssr codebook
}
