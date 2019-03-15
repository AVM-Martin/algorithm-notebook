typedef pair<pii,int> iii;
int blocks,n,l,r,q,ans;
int answer[300100],cnt[1000100],a[300100];
vector<iii> v;

bool cmp(iii x, iii y){
	if(x.fi.fi/blocks == y.fi.fi/blocks)
		return x.fi.se<y.fi.se;
	return x.fi.fi/blocks < y.fi.fi/blocks;
}
void add(int position){
	if(++cnt[a[position]]==1)ans++;
}
void remove(int position){
	if(--cnt[a[position]]==0)ans--;
}
int main(){
	scanf("%d",&n);
	blocks =(int)sqrt(n);
	FOR(i,n)scanf("%d",&a[i]);
	scanf("%d",&q);
	FOR(i,q){
		scanf("%d%d",&l,&r); l--; r--;
		v.pb(mp(mp(l,r),i));
	}
	sort(v.begin(),v.end(),cmp);
	int currentL = 0, currentR = -1;
	FOR(i,(int)v.size()){
		l = v[i].fi.fi; r = v[i].fi.se;
		int idx = v[i].se;
		while(currentR < r)add(++currentR);
		while(currentR > r)remove(currentR--);
		while(currentL < l)remove(currentL++);
		while(currentL > l)add(--currentL);
		answer[idx]= ans;
	}
	FOR(i,q)printf("%d\n",answer[i]);
}