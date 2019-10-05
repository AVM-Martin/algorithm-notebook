#pragma GCC optimize("O3")
const int OO=(int)1e9;
const ll INF=(ll)2e18;
#define FOR(i,n) for(int i=0;i<n;i++)
#define REPP(i,l,r,c) for(int i=l; i<=r; i+=c)
#define REP(i,l,r) REPP(i,l,r,1)
#define FORD(i,n) for(int i=n-1; i>=0; i--)
#define REVV(i,l,r,c) for(int i=l; i>=r; i-=c)
#define REV(i,l,r) REVV(i,l,r,1)

int irand(int lo,int hi){ // random
	return ((double)rand()/(RAND_MAX+1.0)) * (hi-lo+1) + lo;
}
string toString(ll x){ // ll to string
	stringstream ss;  ss << x;  return ss.str();
}
ll toNumber(string S){ // string to ll
	ll ret;  sscanf(S.c_str(),"%lld",&ret);  return ret;
}
void ioSync(){ //iostream sync
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
}
