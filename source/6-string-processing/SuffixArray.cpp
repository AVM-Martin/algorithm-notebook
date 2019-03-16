int bucket[100005];  pair<pii,int> temp[100005];
void radix(pair<pii,int> ret[], int xxxxx, int n){
    //second
    FOR(i,N+3) bucket[i] = 0;
    REP(i,1,n) bucket[ret[i].fi.se]++;
    REP(i,1,N) bucket[i] += bucket[i-1];
    REV(i,n,1) temp[bucket[ret[i].fi.se]--] = ret[i];
    //first
    FOR(i,N+3) bucket[i] = 0;
    REP(i,1,n) bucket[temp[i].fi.fi]++;
    REP(i,1,N) bucket[i] += bucket[i-1];
    REV(i,n,1) ret[bucket[temp[i].fi.fi]--] = temp[i];
}
int dat[100005][25];  pair<pii,int> ret[100005];
void sparse(char s[], int n){
	FOR(i,100003) FOR(j,23) dat[i][j] = -1;
	FOR(j,22){
		//copy data
		ret[0] = mp(mp(-1,-1),-1);
		FOR(i,n){
			ret[i+1].se = i;
			if(j == 0) ret[i+1].fi = mp((int)(s[i]-'a'+1), -1);
			else{
				int mask = (i + (1<<(j-1))) % n;
				ret[i+1].fi.fi = dat[i][j-1];
				ret[i+1].fi.se = dat[mask][j-1];
		}   }
		sort(ret+1,ret+1+n); // radix(ret, 1,n);
		//iterate
		int pos = 0;
		REP(i,1,n){
			if(ret[i-1].fi == ret[i].fi) dat[ret[i].se][j] = pos;
			if(ret[i-1].fi != ret[i].fi) dat[ret[i].se][j] = ++pos;
}	}	}
int solve(){
	int n;  char s[200005];  scanf("%d %s", &n, s);  sparse(s,n);
	int res = 0;
	FOR(pos,n){
		int posa = pos, posr = res;
		FORD(i,20) if(n&(1<<i)){
			if(dat[posa][i] == dat[posr][i]){
				posa = (posa+(1<<i))%n;
				posr = (posr+(1<<i))%n;
				continue;
			}
			if(dat[posa][i] < dat[posr][i]) res = pos;
			break;
	}	}
	printf("%d\n", res);
}