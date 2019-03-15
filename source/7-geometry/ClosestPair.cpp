const double inf = 10000.0;
typedef long long ll;
struct point{ double x, y;  };
int cmp(const point &a, const point &b) {
	return a.x < b.x;
}
int n, buff[10005], Y[10005], Yak[10005];
point X[10005];
double conquer(int l, int mid, int r, double dn){
	for(int i=l,j=mid+1,k=l; i<=mid || j<=r; k++){
		if((j>r) || (i<=mid && X[Y[i]].y<X[Y[j]].y))
			buff[k] = Y[i], i++;
		else buff[k] = Y[j], j++;
	}
	int nak = 0;
	REP(i,l,r){
		Y[i] = buff[i];
		if(fabs(X[mid].x - X[Y[i]].x) <= dn){
			Yak[nak++] = Y[i];
	}	}
	double ret = dn;
	FOR(i,nak) REP(j,i+1,nak-1){
		if (fabs(X[Yak[i]].y-X[Yak[j]].y)>ret) break;
		ret = min(ret,dist(X[Yak[i]], X[Yak[j]]));
	}
	return ret;
}
double divide(int l, int r){
	double ret = inf;
	if(l < r){
		double dl = divide(l, (l+r)/2);
		double dr = divide((l+r)/2+1, r);
		ret = conquer(l, (l+r)/2, r, min(dl, dr));
	}
	return ret;
}
int main(){
	while(scanf("%d", &n) != EOF && n){
		FOR(i,n) scanf("%lf %lf", &X[i].x, &X[i].y);
		sort(X,X+n, cmp);
		FOR(i,n) Y[i] = i;
		double ans = divide(0,n-1);
		if (fabs(ans-inf) <= EPS) printf("INF\n");
		else printf("%.4lf\n", ans);
}	}