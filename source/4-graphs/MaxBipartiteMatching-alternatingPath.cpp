vi match, vis;
int aug(int l){
	if(vis[l]) return 0;
	vis[l] = 1;
	for(auto r: AdjList[l]) if(match[r]==-1 || aug(match[r]))
		match[r] = l, return 1;
	return 0;
}