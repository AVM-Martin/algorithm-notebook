char s[MAX+5], pat[MAX+5];  int KMP[MAX+5];
int buildKMP(int k){
	int lpat = strlen(pat), pos = KMP[0] = -1;
	FOR(i,lpat){
		while(pos>=0 && pat[i]!=pat[pos]) pos = KMP[pos];
		KMP[i+1] = ++pos;
	}
	int ls = strlen(s), res = pos = 0;
	FOR(i,ls){
		while(pos>=0 && s[i]!=pat[pos]) pos = KMP[pos];
		if(++pos == la) pos = KMP[pos], res++;
	}
	return res; // return the number of occurrences
}
