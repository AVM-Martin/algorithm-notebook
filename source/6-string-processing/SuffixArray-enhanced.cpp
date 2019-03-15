#define MAX_N 100000
typedef struct{ int a[2], idx; } ttemp;
bool cmp(const ttemp& a, const ttemp& b){
	return (a.a[0]==b.a[0]) ? (a.a[1]<b.a[1]) : \
		 (a.a[0]<b.a[0]);
}
ttemp L[MAX_N], temp[MAX_N];
int step, p[20][MAX_N], lt, lq, a[MAX_N+1];

void rasort(ttemp x[], int n){
	int k = -1;  memset(a,0,sizeof(a));
	FOR(i,n)a[x[i].a[1]+1]++, k = max(k,x[i].a[1]+1);
	REP(i,1,k)a[i] += a[i-1];
	FORD(i,n)temp[ --a[x[i].a[1]+1] ] = x[i];
	memset(a,0,sizeof(a));  k = -1;
	FOR(i,n){
		a[temp[i].a[0]+1]++;
		k = max(k, temp[i].a[0]+1);
	}
	REP(i,1,k)a[i] += a[i-1];
	FORD(i,n)x[ --a[temp[i].a[0]+1] ] = temp[i];
}
void generate(char s[], int p[][MAX_N]){
	int cnt;  FOR(i,lt)p[0][i] = s[i];
	for(step=1,cnt=1; (cnt>>1)<lt; step++,cnt<<=1){
		FOR(i,lt){
			L[i].a[0] = p[step-1][i];  L[i].idx = I;
			L[i].a[1] = (i+cnt<lt)?p[step-1][i+cnt]:-1;
		}
		rasort(L,lt);  //sort(L,L+lt); => n log^2 n
		FOR(i,lt) p[step][L[i].idx] = (i && L[i].a[0] \
			== L[i-1].a[0] && L[i].a[1] == L[i-1].a[1]) \
			? p[step][L[i-1].idx] : i;
	}
	step--;
}
char pattern[1100], text[100010];
//compare pattern suffix[idx]
inline int compare(int idx){
	int i = 0;
	for(;i<lq && idx<lt; i++,idx++){
		if(pattern[i] > text[idx])return -1;
		if(pattern[i] < text[idx])return 1;
	}
	return (i == lq) ? 0 : -1;
}
inline int lcp(int x, int y){
	if(x == y)return lt-x;
	int res = 0;
	for(int k = step-1; k>=0 && x<lt && y<lt; k--)
		if (p[k][x]==p[k][y])
			x+=(1<<k),y+=(1<<k),res+=(1<<k);
	return res;
}
//cari many pattern pada long text, preprocess text
int L = 0, R = lt-1, mid, found = false;
while(L <= R && !found){
	mid = (L+R)>>1;  int temp = compare(arr[mid]);
	if(temp==0)found = 1;
	else if(temp==1)R = mid-1;
	else L = mid+1;
}
//Longest palindrome
S = S + rev(S), edit LCP
for(int i=0;i<lt/2-1 ;i++){
	res >?= lcp(lt-i-1,i+1);
	if(i)res >?= 1 + lcp(lt-i,i+1);
}
//Distinct substring
if(lt&1)res = ((lt+1)>>1)*lt;
else res = (lt>>1) * (lt+1);
FOR(i,lt)arr[p[step-1][i]] = i;
FOR(i,lt-1)res -= lcp(arr[i],arr[i+1]);
//longest palindrome, maximum K change
int longpal(int left, int right, int k){
	int temp = 0, a;
	for(int j=0; j<=k; ){
		a = lcp(right,left);
		temp += 2*a;  left +=a;  right+=a;
		if(a==0){
			if(j==k)break;
			temp+=2;  left++;  right++;  j++;
		}
		if(left>= lt || right >= lt/2)break;
	}
	return temp;
}