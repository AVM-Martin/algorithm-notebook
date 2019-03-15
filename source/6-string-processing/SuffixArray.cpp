int dat[100005][25];  pair<pii,int> ret[100005];

void sparse(char* s, int n){
	FOR(i,100003) FOR(j,23)dat[i][j] = -1;
	FOR(j,20){
		//copy data
		ret[0] = mp(mp(-1,-1),-1);
		FOR(i,n){
			ret[i+1].se = i;
			if(j==0)ret[i+1].fi = mp((int)s[i],-1);
			else{
				int mask = (i+(1<<(j-1)))%n;
				ret[i+1].fi.fi = dat[i][j-1];
				ret[i+1].fi.se = dat[mask][j-1];
		}   }
		sort(ret+1,ret+1+n);
		//iterate
		int pos=0;
		REP(i,1,n){
			if(ret[i-1].fi == ret[i].fi)
				dat[ret[i].se][j] = pos;
			else dat[ret[i].se][j] = ++pos;
}	}	}
int main(){
	int t,n;  char s[200005];
	scanf("%d",&t);
	while(t--){
		scanf("%d %s",&n,s);  sparse(s,n);
		int res = 0;
		FOR(i,n){
			//compare with pos
			int posa = i, posr = res;
			FORD(j,20) if(n&(1<<j)){
				if(dat[posa][j] == dat[posr][j]){
					posa = (posa+(1<<j))%n;
					posr = (posr+(1<<j))%n;
					continue;
				}
				if(dat[posa][j] < dat[posr][j])res = i;
				break;
		}	}
		printf("%d\n",res);
}	}