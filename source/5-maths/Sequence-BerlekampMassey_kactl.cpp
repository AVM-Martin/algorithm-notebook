// Source: https://github.com/kth-competitive-programming/kactl/
// Desc  : Recovers any $n$-order linear recurrence relation from the
//         first 2n terms of the recurrence. Useful for guessing
//         linear recurrences after brute-forcing the first terms.
//         Should work on any field, but numerical stability for
//         floats is not guaranteed. Output will have size <= n.
// Usage : BerlekampMassey({0, 1, 1, 3, 5, 11}) // {1, 2}
// Status: bruteforce-tested mod 5 for n <= 5 and all s
vector<ll> BerlekampMassey(vector<ll> s){
	int n = (int)s.size(), L = 0, m = 0;  vector<ll> C(n), B(n), T;
	C[0] = B[0] = 1;  ll b = 1;
	FOR(i,n){
		++m;  ll d = s[i] % mod;
		REP(j,1,L) d = (d + C[j]*s[i-j]) % mod; // chosen mod = 5
		if(!d) continue;
		T = C;  ll coef = d*fastExp(b, mod-2) % mod;
		REP(j,m,n-1) C[j] = (C[j] - coef*B[j-m]) % mod;
		if(2*L > i) continue;
		L = i + 1 - L;  B = T;  b = d;  m = 0;
	}
	C.resize(L+1);  C.erase(C.begin());
	for(auto& x: C) x = (mod-x) % mod;  return C;
}
