// Kadane 1D
k = 0;  l = 0;  s = -INF;  t = 0;  j = 1;
for (int i=1; i<=n; i++) {
	t += a[i];
	if (t > s) k = j, l = i, s = t;
	if (t < 0) t = 0, j = i+1;
}
// Kadane 2D
int N, t = 0, a[100][100], pr[100];
int S = 1<<31, s=0, k, l, x1=0,x2=0, y1=0,y2=0, j;

for (int z=0; z<N; z++) {
	for (int i=0; i<N; i++) pr[i] = 0;
	for (int i=z; i<=N-1; i++) {
		t = j = k = l = 0, s = 1<<31;
		for (int i=0; i<N; i++) {
			pr[i] = pr[i]+ a[x][i];  t = t + pr[i];
			if (t > s) s = t, k = i, l = j;
			if (t < 0) t = 0, j = i + 1;
		}
		if (s > S) S = s, x1 = x, y1 = k, x2 = z, y2 = l;
}	}
cout << x1 <<" "<< y1 <<" "<< x2 <<" "<< y2 << endl << S;
