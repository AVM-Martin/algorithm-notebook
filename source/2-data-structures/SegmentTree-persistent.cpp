class ST{ // example: persistent PURQ
	int n, posHead, posDat;
	int head[100005], dat[1800005];
	pii next[1800005]; // head * log(n)
	// private function
	int __upd(int,int,int,int,int);
	int __que(int,int,int,int,int);
public:
	int reset(int);
	int update(int);
	int query(int,int,int);
};
int ST::__upd(int idx, int l, int r, int pos, int idx2){
	if(idx == idx2) return dat[idx];
	if(pos<l || r<pos) return dat[idx];
	if(l == r) return dat[idx] = 1;
	//
	pii& ptr = next[idx], ptr2 = next[idx2];
	ptr = ptr2;
	int mid = (l+r)>>1;
	if(pos <= mid)ptr.fi = ++posDat;
	else ptr.se = ++posDat;
	//
	int reta = __upd(ptr.fi,l,mid,pos,ptr2.fi);
	int retb = __upd(ptr.se,mid+1,r,pos,ptr2.se);
	return dat[idx] = reta + retb;
}
int ST::__que(int idx, int l, int r, int a, int b){
	if(r<a || b<l) return dat[0]; // default data
	if(a<=l&&r<=b) return dat[idx];
	//
	int mid = (l+r)>>1;  pii& ptr = next[idx];
	int reta = __que(ptr.fi,l,mid,a,b);
	int retb = __que(ptr.se,mid+1,r,a,b);
	return reta + retb;
}
int ST::reset(int _n){
	n = _n;  posDat = -1;
	head[posHead = 0] = ++posDat;
	dat[0] = 0;  next[0] = mp(0,0);
	return 0;
}
int ST::update(int pos){
	head[++posHead] = ++posDat;
	int prevHead = head[poshead-1];
	return __upd(head[posHead], 1,n, pos, prevHead);
}
int ST::query(int h, int l, int r){
	return __que(head[h], 1,n, l,r);
}