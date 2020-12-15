// lps[i] means the longest palindromic substring centered at i
// When i is even, it's between chars. Otherwise, it's on (i/2) char
// This algorithm runs in O(n)
int lps[2*N+5];
void manacher(char s[], int n) {
	for (int i=0; i<2*N+3; i++) lps[i] = 0;
	lps[0] = 0;  lps[1] = 1;
	for (int i=2; i<=2*n; i++) {
		int l = i/2, r = (i-1)/2;  l -= lps[i]/2;  r += lps[i]/2;
		// widen
		while (l != 0 && r != n-1 && s[l-1] == s[r+1]) l--, r++;
		if ((lps[i] = r-l+1) <= 1) continue;
		// jump
		int best = i-1;  while (lps[best]-best < lps[i]-i) best--;
		for (int j=i-1, k=i+1; j>best; j--,k++) lps[k] = lps[j];
		lps[i+i-best] = min(lps[best], lps[i]-(i-best));
		i = i+i-best-1;
}	}
