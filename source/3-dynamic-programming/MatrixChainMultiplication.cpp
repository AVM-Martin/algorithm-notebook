const int MAX=100;
int p[MAX+1], m[MAX+1][MAX+1], s[MAX+1][MAX+1];

void MCM(int n){
	for (int i=0; i<n+1; i++) m[i][i]=0;
	for (int l=2; l<=n; l++) for (int i=1; i<=n-l+1; i++) {
		int j = i+l-1;   m[i][j] = INF;
		for (int k=i; k<=j-1; k++) {
			int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
			if (q < m[i][j]) m[i][j] = q, s[i][j] = k;
}	}	}
void print_MCM(int i, int j) {
	if (i == j) { printf("A%d", i);  return; }
	printf("(");    print_MCM(i, s[i][j]);
	printf(" x ");  print_MCM(s[i][j]+1, j);  printf(")");
}
int main() {
	int n;
	while (scanf("%d",&n) != EOF, n) {
		for (int i=0; i<n; i++) scanf("%d %d", &p[i], &p[i+1]);
		MCM(n);  print_MCM(1,n);  puts("");
}	}
