string kthpermute(ll k, string s){
	int len = s.length();  char ss[len+2];
	sprintf(ss, "%s", s.c_str());
	ll fac = 1;  REP(i,2,len-1) fac = (ll)i * (ll)fac;
	FOR(i,len-1){
		int tidx = (k/fac) % (len-i);  char ch=ss[i+tidx];
		REV(j,i+tidx,i+1) ss[j] = ss[j-1];
		ss[i] = ch;  fac /= (ll)(len-i-1);
	}
	return (s = ss);
}
// inside int main
string s = "abcdefghijklmnopqrst";
printf("%s\n", kthpermute(1234567654321, s).c_str());
