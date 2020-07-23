string kthpermute(long long k, string s) {
	int len = s.length();  char ss[len+2];
	sprintf(ss, "%s", s.c_str());
	ll fac = 1;  for (int i=2; i<=len-1; i++) fac = (ll)i * (ll)fac;
	for (int i=0; i<len-1; i++) {
		int tidx = (k/fac) % (len-i);  char ch=ss[i+tidx];
		for (int j=i+tidx; j>=i+1; j--) ss[j] = ss[j-1];
		ss[i] = ch;  fac /= (ll)(len-i-1);
	}
	return (s = ss);
}
// inside int main
string s = "abcdefghijklmnopqrst";
printf("%s\n", kthpermute(1234567654321, s).c_str());
