const int MAXN = 200005;  const int INF = (int)1e9;
int n, q, euler[2*MAXN];
int level[2*MAXN], h[2*MAXN], id;
// h[i] = idx of the first occurence of node i in E
vi adj[maxn]; bool vis[maxn];
struct node{int level,id;} st[4*2*MAXN];

void eulerTour(int u, int p, int l){
	euler[id] = u;  level[id] = l;
	if(!vis[u])vis[u] = 1, h[u] = id;
	id++;
	for(auto v: adj[u]) if(v != p){
		eulerTour(v, u, l+1);
		euler[id] = u;  level[id++] = l;
}	}
void build(int p, int l, int r){
	if(l == r){
		st[p].level = level[l]; st[p].id = l; return;
	}
	int mid = (l+r)/2;
	build(p*2, l, mid);  build(p*2+1, mid+1, r);
	st[p].level = min(st[p*2].level,st[p*2+1].level);
	st[p].id = (st[p*2].level < st[p*2+1].level) ? \
		st[p*2].id : st[p*2+1].id;
}
node query(int p,int l,int r, inti,int j){
	if(l > j || r <i){
		node ret;  ret.level = INF;  return ret;
	}
	if(l >= I && r <= j)return st[p];
	int mid = (l+r)/2;
	node ret1 = query(p*2,l,mid,i,j);
	node ret2 = query(p*2+1,mid+1,r,i,j);
	return (ret1.level < ret2.level) ? ret1 : ret2;
}
int lca(int r,int u,int v){
	int a = min(h[u],h[v]), b = max(h[u],h[v]);
	int lca_id = query(1,1,2*n-1,a,b).id;
	return euler[lca_id];
}
int main(){
	int r, u, v;
	scanf("%d",&n);
	FOR(i,n-1){
		scanf("%d%d",&u,&v);
		adj[u].pb(v); adj[v].pb(u);
	}
	memset(euler,0,sizeof(euler));
	memset(level,0,sizeof(level));
	memset(h,0,sizeof(h));
	memset(vis,0,sizeof(vis));
	id =1;  eulertour(1,1,0);
	memset(st,0,sizeof(st));
	build(1,1,2*n-1);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&r,&u,&v);
		int lca1, lca2, lca3, ans;
		lca1 = lca(1,r,u);
		lca2 = lca(1,r,v);
		lca3 = lca(1,u,v);
		if(lca1 == lca2 && lca2 == lca3) ans = lca1;
		else if(lca1==lca2 && lca3!=lca1) ans = lca3;
		else if(lca1==lca3 && lca2!=lca1) ans = lca2;
		else if(lca2==lca3 && lca1!=lca2) ans = lca1;
		printf("%d\n",ans);
}	}