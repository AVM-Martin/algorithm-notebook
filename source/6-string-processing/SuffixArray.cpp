int bucket[100005];  pair< pair<int,int> ,int> temp[100005];
void radix(pair< pair<int,int> ,int> ret[], int xxxxx, int n){
	// second
	for (int i=0; i<N+3; i++) bucket[i] = 0;
	for (int i=1; i<=n; i++)  bucket[ret[i].first.second]++;
	for (int i=1; i<=N; i++)  bucket[i] += bucket[i-1];
	for (int i=n; i>=1; i--)  temp[bucket[ret[i].first.second]--] = ret[i];
	// first
	for (int i=0; i<N+3; i++) bucket[i] = 0;
	for (int i=1; i<=n; i++)  bucket[temp[i].first.first]++;
	for (int i=1; i<=N; i++)  bucket[i] += bucket[i-1];
	for (int i=n; i>=1; i--)  ret[bucket[temp[i].first.first]--] = temp[i];
}
int dat[100005][25];  pair< pair<int,int> ,int> ret[100005];
void sparse(char s[], int n) {
	for (int i=0; i<100003; i++) for (int j=0; j<23; j++) dat[i][j] = -1;
	for (int j=0; j<22; j++) {
		// copy data
		ret[0] = make_pair(make_pair(-1,-1),-1);
		for (int i=0; i<n; i++) {
			ret[i+1].second = i;
			if (j == 0) ret[i+1].first = make_pair((int)(s[i]-'a'+1), -1);
			else {
				ret[i+1].first.first = dat[i][j-1];
				ret[i+1].first.second = dat[(i + (1<<(j-1))) % n][j-1];
		}   }
		sort(ret+1, ret+1+n); // radix(ret, 1,n);
		// iterate
		int pos = 0;
		for (int i=1; i<=n; i++) {
			if(ret[i-1].first == ret[i].first) dat[ret[i].second][j] = pos;
			if(ret[i-1].first != ret[i].first) dat[ret[i].second][j] = ++pos;
}	}	}
int getLCP(int a, int b, int n, int res=0) {
	if (a == b) return n;
	for (int i=22-1; i>=0; i--) if (dat[a][i] == dat[b][i]) {
		a += (1<<i), b += (1<<i), res += (1<<i);
	}
	return res;
}
int solve() {
	int n;  char s[200005];  scanf("%d %s", &n, s);  sparse(s,n);  int res = 0;
	for (int pos=0; pos<n; pos++) {
		int posa = pos, posr = res;
		for (int i=20-1; i>=0; i--) if (n & (1<<i)) {
			if (dat[posa][i] == dat[posr][i]) {
				posa = (posa+(1<<i))%n;  posr = (posr+(1<<i))%n;  continue;
			}
			if (dat[posa][i] < dat[posr][i]) res = pos;
			break;
	}	}
	printf("%d\n", res);
}
