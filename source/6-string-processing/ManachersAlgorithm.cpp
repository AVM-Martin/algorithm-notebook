// lps[i] means the longest palindromic substring centered at i
// When i is even, it's between chars. Otherwise, it's on (i/2) char
// This algorithm runs in O(n)
int lps[200005];  char s[100005];
void manacher(int n){
	FOR(i,200003) lps[i]=0;  lps[0]=0;  lps[1]=1;
	REP(i,2,2*n){
		int l=i/2, r=(i-1)/2;  l -= lps[i]/2;  r += lps[i]/2;
		// widen
		while(l!=0 && r!=n-1 && s[l-1]==s[r+1]) l--, r++;
		lps[i] = r-l+1;
		if(lps[i] <= 1) continue;
		// jump
		int best = i-1;  while(lps[best]-best < lps[i]-i) best--;
		for(int j=i-1, k=i+1; j>best; j--,k++) lps[k] = lps[j];
		lps[i+i-best] = min(lps[best], lps[i]-(i-best));
		i = i+i-best-1;
}	}