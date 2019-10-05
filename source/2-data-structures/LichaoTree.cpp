int tree[800005];  ll b[200005], ans[200005];
ll f(ll x, int y){ return b[y]*x + ans[y]; }

void add(int idx, int l, int r, int v){
	int m = (l+r) >> 1;
	bool lef = f(l-N2-1, v) < f(l-N2-1, tree[idx]);
	bool mid = f(m-N2-1, v) < f(m-N2-1, tree[idx]);
	if(mid) swap(tree[idx], v);
	if(l == r) return;
	if(lef != mid) add(idx*2  , l  ,m, v);
	if(lef == mid) add(idx*2+1, m+1,r, v);
}
ll query(int idx, int l, int r, int v){
	int m = (l+r) >> 1;  ll res = f(v, tree[idx]);
	if(l == r) return f(v, tree[idx]);
	if(v+N2+1 <= m) return min(res, query(idx*2  , l  ,m, v));
	if(v+N2+1  > m) return min(res, query(idx*2+1, m+1,r, v));
}
