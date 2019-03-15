void topoSort(int v){
	vis[v] = 1;
	FOR(i,(int)ad[v].size())
		if(!vis[ad[v][i]]) topoSort(ad[v][i]);
	topoSorted.pb(v);
}
int main(){
	topoSorted.clear();
	REP(i,N) if(!vis[i]) topoSort(i);
	reverse(topoSorted.begin(),topoSorted.end());
}