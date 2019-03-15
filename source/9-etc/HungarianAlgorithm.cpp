int cost[64][64], lvisit[64], rvisit[64];
int lvalue[64], rvalue[64], rmatch[64], n;

bool findmatch(int s){
	lvisit[s] = true;
	FOR(i,n){
		if(rvisit[i]||lvalue[s]+rvalue[i]!=cost[s][i])
			continue;
		rvisit[i] = true;
		if(rmatch[i]==-1 || findmatch(rmatch[i])){
			rmatch[i] = s;  return true;
	}	}
	return false;
}
void normalize(){
	int down = INF;
	FOR(i,n) if(lvisit[i]) FOR(j,n) if(!rvisit[j])
		down = min(down, \
			lvalue[i]+rvalue[j]-cost[i][j]);
	FOR(i,n){
		if(lvisit[i])lvalue[i] -= down;
		if(rvisit[i])rvalue[i] += down;
}	}
int calc(){
	FOR(i,n){
		lvalue[i] = *max_element(cost[i],cost[i]+n);
		rvalue[i] = 0;
	}
	FOR(i,n)rmatch[i] = -1;
	FOR(i,n){
		FILL(lvisit,0);  FILL(rvisit,0);
		if(findmatch(i))continue;
		i--;  normalize();
	}
	int ret = 0;
	FOR(i,n)ret += cost[rmatch[i]][i];
	return ret;
}