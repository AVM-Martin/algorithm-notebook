char s[MAX+5], pat[MAX+5];  int KMP[MAX+5];
int buildKMP() {
	int lpat = strlen(pat), pos = KMP[0] = -1;
	for (int i=0; i<lpat; i++) {
		while (pos >= 0 && pat[i] != pat[pos]) pos = KMP[pos];
		KMP[i+1] = ++pos;
	}
	int ls = strlen(s), res = pos = 0;
	for (int i=0; i<ls; i++) {
		while (pos>=0 && s[i]!=pat[pos]) pos = KMP[pos];
		if (++pos == lpat) pos = KMP[pos], res += 1;
	}
	return res; // return the number of occurrences
}
