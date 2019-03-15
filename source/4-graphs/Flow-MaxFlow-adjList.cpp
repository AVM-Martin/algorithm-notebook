const int maxv = 100, INF = (int)1e9;
int res[maxv][maxv], s, t, mf, f;  vi p, adj[maxv];

void augment(int v, int minedge){
	if(v == s){ f = minedge; return; }
	else if(p[v]!=-1){
		augment(p[v], min(minedge, res[p[v]][v]));
		res[p[v]][v]-= f;
		res[v][p[v]]+= f;
}	}
int main(){
	mf = 0;
	while(1){ // BFS
		f = 0;  vi dist(maxv,INF); dist[s]=0;
		queue<int> q;  q.push(s);  p.assign(maxv,-1);
		while(!q.empty()){
			int u = q.front();  q.pop();
			if(u == t)break;
			for(auto v: adj[u])
				if(dist[v]==INF && res[u][v]>0)
					dist[v] = dist[u]+1, p[v] = u, q.push(v);
		}
		augment(t,INF);  mf += f;  if(f == 0)break;
	}
	printf("%d\n",mf);
}