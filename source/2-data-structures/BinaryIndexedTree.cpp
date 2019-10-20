int n, dat[100005];
int LSOne(int n) { return (n&-n); }
void upd(int pos, int val) {
    for (int i=pos; i<=n; i+=LSOne(i)) dat[i] += val; // i|=i+1
}
int que(int pos, int res = 0) {
    for (int i=pos; i>=1; i-=LSOne(i)) res += dat[i]; // i=(i&(i+1))-1
	return res;
}
