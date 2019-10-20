class Tree{
	int num, idx, n, elder;
	int dat[50005<<2];   //segment tree data
	int par[50005][25];  //LCA parent
	int depth[50005], hashh[50005], chain[50005], headd[50005];
	vector<int> child[50005];
	int count[50005];    // count subtree
	//generate function
	int generateDepthAndCountSubtree(int u, int _depth=0);
	void generateHLD(int u) {
		hashh[u] = ++idx;  chain[u] = num;
		pair<int,int> bigChild = make_pair(-1,-1);
		for (int v: child[u]) {
			if (count[v] > bigChild.second && v != par[u][0]) {
				bigChild = make_pairp(v, count[v]);
		}	}
		if (bigChild.fi != -1) generateHLD(bigChild.fi);
		for (int v: child[u]) if (v != bigChild.first && v != par[u][0]){
			chain[v] = ++num;  headd[num] = v;  generateHLD(v);
	}	}
	int getNthPar(int u, int _n);
	int getLowestCommonAncestor(int u, int v);
	void __upd(int idx, int l, int r, int a, int b, int val);
	int __que(int idx, int l, int r, int pos);
public:
	int reset(int _n) {
		for (int i=0; i<_n+3; i++) {
			for (int j=0; j<23; j++) par[i][j] = 0;
			child[i].clear();
			hashh[i] = depth[i] = count[i] = 0;
			chain[i] = headd[i] = -1;
		}
		for (int i=0; i<(_n<<2); i++) dat[i] = 0;
		num = idx = elder = 0;
		return n = _n;
	}
	void addEdge(int u, int v); // bidirectional edge
	void generate() {
		//generate LCA
		generateDepthAndCountSubtree(elder);
		for (int j=1; j<=20; j++) for (int i=0; i<n-1; i++) {
			par[i][j] = par[ par[i][j-1] ][j-1];
		}
		//generate HLD :)
		chain[elder]=++num;  headd[num]=elder;  generateHLD(elder);
	}
	void upd(int u, int v, int val) {
		int anc = getLowestCommonAncestor(u,v);
		for (int fron; ; u = par[fron][0]) { // run from U
			fron = (chain[anc] == chain[u]) ? anc : headd[chain[u]];
			__upd(1, 1,n, hashh[fron],hashh[u], val);
			if (chain[anc] == chain[u]) break;
		}
		for (int fron; ; v = par[fron][0]) { // run from V
			fron = (chain[anc] == chain[v]) ? anc : headd[chain[v]];
			__upd(1, 1,n, hashh[fron],hashh[v], val);
			if (chain[anc] == chain[v]) break;
		}
		//substract anc
		__upd(1, 1,n, hashh[anc],hashh[anc], -val);
	}
	int que(int pos) { return __que(1, 1,n, hashh[pos]); }
};
