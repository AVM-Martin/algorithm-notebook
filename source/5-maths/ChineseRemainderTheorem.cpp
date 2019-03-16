// Assume that f(0)=1 and 0^0=1.  f(n) = (n%10)^f(n/10) for all n
// bigger than zero. Please calculate f(n)%m. (2 <= n, m <= 10^9)
ll inverse(ll a, ll m){ return mPow(a,phi(m)-1,m); }
ll CRT( vector<pair<LL,int>> data ) {
	ll M = 1;
	For(auto x: data)M *= x.se;
	ll ret = 0LL;
	For(auto x: data){
		ll temp = x.fi * (M/x.se) * inverse(M/x.se, x.se);
		ret = (ret + temp) % M;
	}
	return ret;
}
int nums[16], n;  const int LIM = 1<<10;
ll brute(ll base, int pos, ll M){
	if(pos==n) return base % M;
	int j = n;  ll pj = 1;
	while(j-1 >= pos){
		ll k = 1;
		FOR(loop,pj){
			K *= nums[j-1];
			if(k >= LIM) return 0;
		}
		pj = k;  j--;
	}
	return mPow(base,pj,M);
}
ll solve(int,ll);
ll doit(int,int);
pair<ll,int> solve2(int pos, ll M){
	ll a = nums[pos];
	if(GCD(a,M) == 1){
		ll b = solve(pos+1,phi((int)M));
		return mp(mPow(a,b,M),M);
	}
	return mp(brute(a,pos+1,M),M);
}
ll solve(int pos, ll M){
	if(M == 1) return 0;
	if(pos == n) return 1;
	if(nums[pos] == (ll)1) return a % M;
	if(nums[pos] == (ll)0) return 0;
	ll m = M;  vector< pair<ll,int> > data;
	for(ll i=2;i*i<=m;i++){
		if(m%i!=0) continue;
		ll p=1;  while(m%i==0) m/=i, p*=i;
		data.pb(solve2(pos,p));
	}
	if(m>1) data.pb(solve2(pos, m));
	return CRT(data);
}
void normalize(){
	nums[n] = 1;  int newN = n;
	FOR(i,n){
		if(nums[i]==1) newN = i, break;
		else if(nums[i]==0){
			int ctr0 = 0;
			while(nums[i+ctr0] == 0) ctr0++;
			if(ctr0%2 == 0) nums[i] = 1, newN = i;
			else if(i-1 >= 0)nums[i-1] = 1, newN = i-1;
			break;
	}	}
	n = newN;  if(nums[n-1] != 1)nums[n++] = 1;
}
ll doit(int x, int m){
	n=0;  while(x) nums[n++] = x%10, x /= 10;
	normalize();  return solve(0,m);
}
// inside int main
int x, m;  scanf("%d %d",&x,&m);  printf("%d\n", (int)doit(x,m));