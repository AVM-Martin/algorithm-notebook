//SA Hansvin
int n, sparse[21][5*N+5];
int bucket[5*N+5]; char s[5*N+5];
pair<pii,int> lst[5*N+5], lst2[5*N+5];
void radix(){
	int nn = max(n,10);
	//second
	memset(bucket,0,sizeof(bucket));
	FOR(i,n) bucket[lst[i].fi.se]++;
	REP(i,1,nn-1) bucket[i] += bucket[i-1];
	FORD(i,n){
		int pos = bucket[lst[i].fi.se]-1;
		bucket[lst[i].fi.se]--;
		lst2[pos] = lst[i];
	}
	//first
	memset(bucket,0,sizeof(bucket));
	FOR(i,n) bucket[lst2[i].fi.fi]++;
	REP(i,1,nn-1) bucket[i]+=bucket[i-1];
	FORD(i,n){
		int pos = bucket[lst2[i].fi.fi]-1;
		bucket[lst2[i].fi.fi]--;
		lst[pos] = lst2[i];
}	}
void build(){
	FOR(i,20){
		FOR(j,n){
			lst[j].se = j;
			if(i==0) lst[j].fi = mp(s[j]-'0',0);
			else lst[j].fi = mp(sparse[i-1][j], \
				sparse[i-1][(j+(1<<(i-1)))%n]);
		}
		radix();
		int pos = 0;
		sparse[i][lst[0].se] = 0;
		REP(j,1,n-1) sparse[i][lst[j].se] = \
			(lst[j].fi==lst[j-1].fi) ? pos:++pos;
}	}
int main(){
	scanf("%d", &n); scanf("%s", s);  build();  int res=0;
	FOR(i,n){
		int posa = i, posr = res;
		FOR(j,20) if(n&(1<<j)){
			if(sparse[j][posr] == sparse[j][posa]){
				posa = (posa+(1<<j))%n;
				posr = (posr+(1<<j))%n;
				continue;
			}
			if(sparse[j][posr] >sparse[j][posa]) res=i;
			break;
	}	}
	printf("%d\n", res);
}
