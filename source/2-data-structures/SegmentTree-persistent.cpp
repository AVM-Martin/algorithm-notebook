class ST { // example: persistent PURQ
	int n, posHead, posDat;
	int head[100005], dat[1800005];
	pair<int,int> next[1800005]; // head * log(n)
	// private function
	int __upd(int idx, int l, int r, int pos, int idx2) {
		if (idx == idx2) return dat[idx];
		if (pos<l || r<pos) return dat[idx];
		if (l == r) return dat[idx] = 1;
		//
		pair<int,int>& ptr = next[idx], ptr2 = next[idx2];  ptr = ptr2;
		int mid = (l+r)>>1;
		if (pos <= mid) ptr.first = ++posDat;
		else ptr.second = ++posDat;
		//
		int reta = __upd(ptr.first , l  ,mid, pos, ptr2.first);
		int retb = __upd(ptr.second, mid+1,r, pos, ptr2.second);
		return dat[idx] = reta + retb;
	}
	int __que(int idx, int l, int r, int a, int b) {
		if (r<a || b<l) return dat[0]; // default data
		if (a<=l&&r<=b) return dat[idx];
		//
		int mid = (l+r)>>1;  pair<int,int>& ptr = next[idx];
		int reta = __que(ptr.first , l  ,mid, a,b);
		int retb = __que(ptr.second, mid+1,r, a,b);
		return reta + retb;
	}
public:
	int reset(int _n) {
		n = _n;  posDat = -1;
		head[posHead = 0] = ++posDat;
		dat[0] = 0;  next[0] = make_pair(0,0);
		return 0;
	}
	int update(int pos) {
		head[++posHead] = ++posDat;
		int prevHead = head[poshead-1];
		return __upd(head[posHead], 1,n, pos, prevHead);
	}
	int query(int h, int l, int r){ return __que(head[h], 1,n, l,r); }
};
