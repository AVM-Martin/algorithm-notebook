const int MAX=100;
int p[MAX+1], m[MAX+1][MAX+1], s[MAX+1][MAX+1];

void MCM(int n){
	FOR(i,n+1) m[i][i]=0;
	REP(l,2,n)REP(i,1,n-l+1){
		int j = i+l-1;   m[i][j] = INF;
		REP(k,i,j-1){
			int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
			if(q < m[i][j]) m[i][j] = q, s[i][j] = k;
}	}	}
void print_MCM(int i, int j){
	if(i == j){ printf("A%d",i);  return; }
	printf("(");  print_MCM(i,s[i][j]);
	printf(" x ");  print_MCM(s[i][j]+1,j); printf(")");
}
int main(){
	int n;
	while(scanf("%d",&n) != EOF, n){
		FOR(i,n) scanf("%d %d", &p[i], &p[i+1]);
		MCM(n);  print_MCM(1,n);  puts("");
}	}