void topoSort(int v) {
	vis[v] = 1;
	for (int x: ad[v]) if (!vis[x]) topoSort(x);
	topoSorted.push_back(v);
}
int inside_main() {
	topoSorted.clear();
	for (int i=0; i<N; i++) if (!vis[i]) topoSort(i);
	reverse(topoSorted.begin(), topoSorted.end());
}
