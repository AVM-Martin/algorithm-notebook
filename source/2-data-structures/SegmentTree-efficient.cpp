// array size: 2N     data inside N..2N-1 0-based

void build(){ // build the tree
	REV(i,n-1,1)t[i] = t[i<<1]+t[i<<1|1];
}
void updPURQ(int pos, int val){
	for(t[pos+=n] = val; pos>>=1;)
		t[pos] = combine(t[pos<<1], t[pos<<1|1]);
}
int queryPURQ(int l, int r){
	int resa = 0, resb = 0;
	for(l+=n,r+=n; l<r; l>>=1,r>>=1){
		if(l&1)res = combine(resa, t[l++]);
		if(r&1)res = combine(t[--r], resb);
	}
	return combine(resa,resb);
}
void updRUPQ(int l, int r, int val){
	for(l+=n,r+=n; l<r; l>>=1,r>>=1){
		if(l&1)t[l++] += val;
		if(r&1)t[--r] += val;
}	}
int queryRUPQ(int pos, int res = 0){
	for(pos+=n; pos>0; pos>>=1) res += t[pos];
	return res;
}
void pushRUPQ(){ // inspect all elements: O(n)
	REP(i,1,n-1){
		t[i<<1] += t[i];  t[i<<1|1] += t[i];
		t[i] = 0;
}	}
// h = height of the tree (log)
int h = sizeof(int) * 8 - __builtin_clz(n);
int d[N];
void apply(int p, int val){
	t[p] += val;  if(p<n) d[p] += val;
}
void build(int p){
	while(p>1){
		p>>=1;  t[p] = max(t[p<<1],t[p<<1|1]) + d[p];
}	}
void push(int p){
	REV(s,h,1){
		int i = p>>s;
		if(d[i] != 0){
			apply(i<<1, d[i]);  apply(i<<1|1, d[i]);
			d[i] = 0;
}	}	}
void inc(int l, int r, int val){
	l+=n;  r+=n;  int lo=l, hi=r;
	for(; l<r; l>>=1, r>>=1){
		if(l&1) apply(l++, val);
		if(r&1) apply(--r, val);
	}
	build(lo);  build(hi-1);
}
int query(int l, int r){
	l+=n; r+=n;  push(l); push(r-1);
	int ret = -INF;
	for(; l<r; l>>=1, r>>=1){
		if(l&1) ret = max(ret, t[l++]);
		if(r&1) ret = max(ret, t[--r]);
	}
	return ret;
}