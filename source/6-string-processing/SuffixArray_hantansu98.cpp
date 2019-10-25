//SA Hansvin
int n, sparse[21][5*N+5];  int bucket[5*N+5];  char s[5*N+5];
pair< pair<int,int> ,int> lst[5*N+5], lst2[5*N+5];
void radix() {
	int nn = max(n,10);
	// second
	memset(bucket, 0, sizeof(bucket));
	for (int i=0; i<n; i++) bucket[lst[i].first.second]++;
	for (int i=1; i<=nn-1; i++) bucket[i] += bucket[i-1];
	for (int i=n-1; i>=0; i--) {
		int pos = bucket[lst[i].first.second]-1;
		bucket[lst[i].first.second]--;
		lst2[pos] = lst[i];
	}
	// first
	memset(bucket,0,sizeof(bucket));
	for (int i=0; i<n; i++) bucket[lst2[i].first.first]++;
	for (int i=1; i<=nn-1; i++) bucket[i] += bucket[i-1];
	for (int i=n-1; i>=0; i--) {
		int pos = bucket[lst2[i].first.first]-1;
		bucket[lst2[i].first.first]--;
		lst[pos] = lst2[i];
}	}
void build() {
	for (int i=0; i<20; i++) {
		for (int j=0; j<n; j++) {
			lst[j].se = j;
			if (i==0) lst[j].fi = make_pair(s[j]-'0',0);
			else lst[j].fi = make_pair(
				sparse[i-1][j], sparse[i-1][(j+(1<<(i-1)))%n]
			);
		}
		radix();
		int pos = 0;
		sparse[i][lst[0].se] = 0;
		for (int j=1; i<=n-1; j++) {
			sparse[i][lst[j].se] = (lst[j].fi == lst[j-1].fi) ? pos : ++pos;
}	}	}
// inside main()
scanf("%d", &n);  scanf("%s", s);  build();  int res = 0;
for (int i=0; i<n; i++) {
	int posa = i, posr = res;
	for (int j=20-1; j>=0; j--) if (n & (1<<j)) {
		if (sparse[j][posr] == sparse[j][posa]) {
			posa = (posa+(1<<j))%n;  posr = (posr+(1<<j))%n;  continue;
		}
		if (sparse[j][posr] > sparse[j][posa]) res = i;
		break;
}	}
printf("%d\n", res);
