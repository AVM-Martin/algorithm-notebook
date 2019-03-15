char s[MAX+5], a[MAX+5];  int pos[MAX+5];

int KMP(int k){
	int la = strlen(a), ls = strlen(s), temp, res;
	temp = pos[0] = -1;
	FOR(i,la){
		while(temp>=0 && a[i]!=a[temp])
			temp = pos[temp];
		pos[i+1] = ++temp;
	}
	temp = res = 0;
	FOR(i,ls){
		while(temp>=0 && s[i]!=a[temp])
			temp = pos[temp];
		if(++temp == la){ temp=pos[temp]; return 1; }
	}
	return 0; //not found
}