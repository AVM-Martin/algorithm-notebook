// Convex Hull Optimization 1
// Recurrence : dp[i] = min{ dp[j] + b[j]*a[i] }
// Condition  : j < i and b[j] >= b[j+1] and a[i] <= a[i+1]
// from O(n^2) become O(n)
struct line { long long a,b;  ll getval(ll x){ return a*x + b; } };
long long xsmall(line l1, line l2, line l3) {
	return (l3.b-l1.b) * (l1.a-l2.a) < (l2.b-l1.b) * (l1.a-l3.a);
}
void getpoint(int k) {
	v.clear();
	for (int i=1; i<=n; i++) {
		line temp;  temp.a = -i;
		temp.b = (i*s[i]) - sum[i] + dp[i][k-1];
		while (v.size() >= 2 && xsmall(v[v.size()-2],v.back(),temp)) {
			v.pop_back();
		}
		v.push_back(temp);
}	}
int main() {
	scanf("%d %d", &n, &k);
	for (int i=1; i<=n; i++) {
		scanf("%lld",&f[i]);  sum[i] = sum[i-1] + (f[i]*(i-1));
		s[i] = s[i-1] + f[i];
	}
	for (int i=1; i<=n; i++) dp[i][1] = sum[i];
	int pt = 0;
	for (int i=2; i<=k; i++) {
		getpoint(i);  pt = 0;
		for (int j=1; j<=n; j++) {
			while (pt<v.size()-1 && v[pt].getval(s[j]) > v[pt+1].getval(s[j])) {
				pt++;
		}	}
		dp[j][i] = sum[j] + v[pt].getval(s[j]);
	}
	printf("%lld\n", dp[n][k]);
}
