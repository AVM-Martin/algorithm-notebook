// Convex Hull Optimization 1
// Recurrence : dp[i] = min{ dp[j] + b[j]*a[i] }
// Condition  : j < i and b[j] >= b[j+1] and a[i] <= a[i+1]
// from O(n^2) become O(n)

// Convex Hull Optimization 2
// Recurrence : dp[i][j] = min{ dp[i-1][k] + b[k]*a[j] }
// Condition  : k < j and b[k] >= b[k+1] and a[j] <= a[j+1]
// from O(kn^2) become O(kn)
struct line{
	ll a,b;  ll getval(ll x){ return a*x+b; }
};
ll xsmall(line l1, line l2, line l3){
	return (l3.b-l1.b)*(l1.a-l2.a) < (l2.b-l1.b)*(l1.a-l3.a);
}
void getpoint(int k){
	v.clear();
	REP(i,1,n){
		line temp;  temp.a = -i;
		temp.b = (i*s[i]) - sum[i] + dp[i][k-1];
		while(v.size()>=2 && xsmall(v[v.size()-2],v.back(),temp))
			v.pob();
		v.pb(temp);
}	}
int main(){
	scanf("%d %d", &n, &k);
	REP(i,1,n){
		scanf("%lld",&f[i]);  sum[i] = sum[i-1] + (f[i]*(i-1));
		s[i] = s[i-1] + f[i];
	}
	REP(i,1,n) dp[i][1] = sum[i];  int pt = 0;
	REP(i,2,k){
		getpoint(i);  pt = 0;
		REP(j,1,n) while(pt<v.size()-1 && v[pt].getval(s[j]) > v[pt+1].getval(s[j])) pt++;
		dp[j][i] = sum[j]+v[pt].getval(s[j]);
	}
	printf("%lld\n", dp[n][k]);
}
