int n, dat[100005];
int LSOne(int n){ return (n&-n); }
void upd(int pos, int val){
	REPP(i,pos,n,LSOne(i)) dat[i] += val; // i|=i+1
}
int que(int pos, int res = 0){
	REVV(i,pos,1,LSOne(i)) res += dat[i]; // i=(i&(i+1))-1
	return res;
}
