const int MAXN = 200005;
int n, q, euler[2*MAXN], level[2*MAXN], h[2*MAXN], id;
// h[i] = idx of the first occurence of node i in E
vi adj[maxn];  bool vis[maxn];
struct node{int level,id;} st[4*2*MAXN];

void eulerTour(int u, int p, int l){
	euler[id] = u;  level[id] = l;
	if(!vis[u]) vis[u] = 1, h[u] = id;
	id++;
	for(auto v: adj[u]) if(v != p){
		eulerTour(v, u, l+1);
		euler[id] = u;  level[id++] = l;
}	}
void build(int p, int l, int r){
	if(l == r){ st[p].level = level[l]; st[p].id = l; return; }
	int mid = (l+r)/2;
	build(2*p  , l  ,mid);  build(2*p+1, mid+1,r);
	st[p].level = min(st[2*p].level, st[2*p+1].level);
	st[p].id = st[2*p+(st[p*2].level>=st[p*2+1].level)].id;
}
node query(int p, int l, int r, int a, int b){
	if(r< a || b< l){ node ret;  ret.level = INF;  return ret; }
	if(a<=l && r<=b) return st[p];
	int mid = (l+r)/2;
	node ret1 = query(2*p  , l  ,mid, a,b);
	node ret2 = query(2*p+1, mid+1,r, a,b);
	return (ret1.level < ret2.level) ? ret1 : ret2;
}
int lca(int r, int u, int v){
	int a = min(h[u],h[v]), b = max(h[u],h[v]);
	int lca_id = query(1, 1,2*n-1, a,b).id;
	return euler[lca_id];
}
int main(){
	int r, u, v; scanf("%d", &n);
	FOR(i,n-1) scanf("%d %d", &u, &v), adj[u].pb(v), adj[v].pb(u);
	//build
	memset(euler,0,sizeof(euler));  memset(vis,0,sizeof(vis));
	memset(level,0,sizeof(level));  memset(h,0,sizeof(h));
	id = 1;  eulertour(1,1,0);
	memset(st,0,sizeof(st));  build(1,1,2*n-1);
	//query
	scanf("%d", &q);
	while(q--){
		scanf("%d %d %d", &r, &u, &v);
		int lca1 = lca(1,r,u);
		int lca2 = lca(1,r,v);
		int lca3 = lca(1,u,v);  int res;
		if(lca1 == lca2) res = lca3;
		if(lca1 == lca3) res = lca2;
		if(lca2 == lca3) res = lca1;
		printf("%d\n", res);
}	}