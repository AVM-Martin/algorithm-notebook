class Tree{
	int num, idx, n, elder;
	int dat[50005<<2];
	//LCA parent
	int par[50005][25];
	int depth[50005], hashh[50005];
	int chain[50005], headd[50005];
	vi child[50005];
	int count[50005]; // count subtree
	//generate function
	void genDepth(int,int);
	void genHLD(int);
	//LCA func
	int getNPar(int,int);
	int getAnc(int,int);
	//segment tree RURQ
	void upd(int,int,int,int,int,int);
	int que(int,int,int,int);
public:
	int reset(int);
	void push(int,int);
	void generate();
	void upd(int,int,int);
	int que(int);
};
void Tree::genDepth(int _node, int _depth=0){
	depth[_node] = _depth;  count[_node] = 1;
	for(auto x: child[_node]){
		if(x == par[_node][0]) continue;
		par[x][0] = _node;
		genDepth(x,_depth+1);
		count[_node] += count[x];
}	}
void Tree::genHLD(int _node){
	hashh[_node] = ++idx;  chain[_node] = num;  pii temp = mp(-1,-1);
	for(auto x: child[_node])
		if(count[x]>temp.se && x!=par[_node][0])
			temp = mp(x,count[x]);
	if(temp.fi != -1) genHLD(temp.fi);
	for(auto x: child[_node]){
		if(x==temp.fi || x==par[_node][0]) continue;
		chain[x]=++num;  headd[num]=x;  genHLD(x);
}	}
int Tree::getNPar(int _node, int _n){
	for(int j=0; j<15 && _n; j++, _n>>=1)
		if(_n&1) _node = par[_node][j];
	return _node;
}
int Tree::getAnc(int _u, int _v){
	//stabilize depth
	if(depth[_u] <  depth[_v]) _v = getNPar(_v, depth[_v]-depth[_u]);
	if(depth[_u]  > depth[_v]) _u = getNPar(_u, depth[_u]-depth[_v]);
	//u==v
	if(_u == _v) return _u;
	//search LCA
	FORD(j,20) if(depth[_u] >= (1<<j) && par[_u][j] != par[_v][j])
		_u = par[_u][j]; _v=par[_v][j];
	return par[_u][0];
}
void Tree::upd(int idx, int a, int b, int l, int r, int val){
	//base case
	if(b<l||r<a) return;
	if(l<=a && b<=r){ dat[idx]+=val;  return; }
	//reccurence
	int mid = (a+b)>>1;
	upd(2*idx  , a  ,mid, l,r, val);
	upd(2*idx+1, mid+1,b, l,r, val);
}
int Tree::que(int idx, int a, int b, int pos){
	//base case
	if(b<pos || pos<a)return 0;
	if(pos<=a && b<=pos)return dat[idx];
	//reccurence
	int mid = (a+b)>>1;
	if(pos <= mid) return dat[idx] + que(2*idx  , a  ,mid, pos);
	if(pos  > mid) return dat[idx] + que(2*idx+1, mid+1,b, pos);
}
//public
int Tree::reset(int _n){
	FOR(i,_n+3){
		FOR(j,23) par[i][j] = 0;
		child[i].clear();
		hashh[i] = depth[i] = count[i] = 0;
		chain[i] = headd[i] = -1;
	}
	FOR(i,_n<<2) dat[i] = 0;  num = idx = elder = 0;
	return n = _n;
}
void Tree::push(int _u, int _v){
	child[_u].pb(_v);  child[_v].pb(_u);
}
void Tree::generate(){
	//generate LCA
	genDepth(elder);
	REP(j,1,20) REP(i,0,n-1) par[i][j] = par[ par[i][j-1] ][j-1];
	//generate HLD :)
	chain[elder] = ++num;  headd[num] = elder;  genHLD(elder);
}
void Tree::upd(int _u, int _v, int _val){
	int anc = getAnc(_u,_v);
	while(1){ // run from U
		int fron = headd[chain[_u]];
		if(chain[anc] == chain[_u]) fron=anc;
		upd(1, 1,n, hashh[fron],hashh[_u], _val);
		if(chain[anc] == chain[_u]) break;
		_u = par[fron][0];
	}
	while(1){ // run from V
		int fron = headd[chain[_v]];
		if(chain[anc] == chain[_v]) fron=anc;
		upd(1, 1,n, hashh[fron],hashh[_v], _val);
		if(chain[anc] == chain[_v]) break;
		_v = par[fron][0];
	}
	//substract anc
	upd(1, 1,n, hashh[anc],hashh[anc], -_val);
}
int Tree::que(int pos){ return que(1, 1,n, hashh[pos]); }