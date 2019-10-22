//enhanced Suffix Array
#define MAX_N 100000
typedef struct { int a[2], idx; } ttemp;
// cari many pattern pada long text, preprocess text
int L = 0, R = lt-1, mid, found = false;
while (L <= R && !found) {
	mid = (L+R)>>1;  int temp = compare(arr[mid]);
	if (temp == 0) found = 1;
	else if (temp == 1) R = mid-1;
	else L = mid+1;
}
// Longest palindrome
S = S + rev(S), edit LCP
for (int i=0; i<lt/2-1; i++) {
	res = max(res, lcp(lt-i-1,i+1));
	if (i) res = max(res, 1+lcp(lt-i,i+1));
}
// Distinct substring
if (lt&1) res = ((lt+1)>>1)*lt;
else res = (lt>>1) * (lt+1);
for (int i=0; i<lt; i++) arr[p[step-1][i]] = i;
for (int i=0; i<lt-1; i++) res -= lcp(arr[i],arr[i+1]);
// longest palindrome, maximum K change
int longpal(int left, int right, int k) {
	int temp = 0, a;
	for (int j=0; j<=k; ) {
		a = lcp(right,left);  temp += 2*a;  left += a;  right += a;
		if (a==0) {
			if (j==k) break;
			temp+=2;  left++;  right++;  j++;
		}
		if (left >= lt || right >= lt/2) break;
	}
	return temp;
}
