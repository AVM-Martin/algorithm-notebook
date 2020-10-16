struct tipetipe { int min, nkurung; };  string s2;
tipetipe memo[305][305];  int n, path[305][305][4];

string buka(int& i, string s) {
	int len = s.length(), angka=0;  string tmp;
	for (; i < len && s[i] != ')'; i++) {
		if ('0' <= s[i] && s[i] <= '9') angka = angka*10 + (s[i]-'0');
		else if (s[i] == '(') {
			string tmp2 = buka(++i, s);
			for (int i=0; i<angka; i++) tmp += tmp2;
			angka = 0;
		} else tmp = tmp + s[i];
	}
	return tmp;
}
tipetipe hohoho(int l, int r) {
	if (memo[r][l].min != -1) return memo[r][l];
	tipetipe ret;  ret.min = r-l+1;  ret.nkurung = 0;  path[l][r][0] = 0;
	for (int i=1; i<=(r-l+1)/2; i++) if((r-l+1) % i == 0) {
		string t1 = s2.substr(0+l,i), t2 = s2.substr(i+l,i);
		int ni = 1, j = i+l;
		for(; t1==t2 && j<=r; t2=s2.substr(j,i)) ni++, j+=i;
		if (ni == (r-l+1)/i) {
			int dig = 0, nii = ni;  while (ni > 0) dig++, ni /= 10;
			tipetipe tmp = hohoho(l,l+i-1);  tmp.min += dig+2;  tmp.nkurung += 2;
			if (tmp.min < ret.min) {
				ret = tmp;            path[l][r][0] = 1;
				path[l][r][1] = nii;  path[l][r][2] = i;
			} else if (tmp.min == ret.min && tmp.nkurung < ret.nkurung) {
				ret = tmp;            path[l][r][0] = 1;
				path[l][r][1] = nii;  path[l][r][2] = i;
	}	}	}
	for (int i=l; i<=r-1; i++) {
		tipetipe left = hohoho(l,i), right = hohoho(i+1,r), tmp;
		tmp.min = left.min + right.min;
		tmp.nkurung = left.nkurung + right.nkurung;
		if (tmp.min< ret.min) {
			ret = tmp;  path[l][r][0]=2;  path[l][r][1]=i;
		} else if (tmp.min == ret.min && tmp.nkurung < ret.nkurung) {
			ret = tmp;  path[l][r][0]=2;  path[l][r][1]=i;
	}	}
	return memo[r][l] = ret;
}
string search_path(int l, int r) {
	string ret;
	if (path[l][r][0] == 0) for (int i=l; i<=r; i++) ret += s2[i];
	if (path[l][r][0] == 1) {
		char tmp[10];  sprintf(tmp, "%d", path[l][r][1]);  ret += tmp;
		ret += "(" + search_path(l,l+path[l][r][2]-1) + ")";
	}
	if (path[l][r][0] == 2) {
		ret += search_path(l,path[l][r][1]);
		ret += search_path(path[l][r][1]+1,r);
	}
	return ret;
}
int inside_main() {
	string s1;  cin >> s1;  int z = 0;  s2 = buka(z,s1);
	memset(memo, -1, sizeof(memo));  hohoho(0,s2.length()-1);
	cout << s2 << endl << search_path(0,s2.length()-1) << endl;
}
// 2(haue)yueuyeuue3(xxzz)zzxx
// hauehaueyueuyeuuexxzzxxzzxxzzzzxx
// 2(haue)yueuyeuue3(xxzz)zzxx
