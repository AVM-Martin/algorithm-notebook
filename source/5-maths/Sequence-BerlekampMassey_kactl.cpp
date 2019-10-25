// Source: https://github.com/kth-competitive-programming/kactl/
// Desc  : Recovers any $n$-order linear recurrence relation from the first 2n
//         terms of the recurrence. Useful for guessing linear recurrences after
//         brute-forcing the first terms. Should work on any field, but numerical
//         stability for floats is not guaranteed. Output will have size <= n.
// Usage : BerlekampMassey({0, 1, 1, 3, 5, 11}) // {1, 2}
// Status: bruteforce-tested mod 5 for n <= 5 and all s
vector<long long> BerlekampMassey(vector<long long> s) {
	int n = (int)s.size(), L = 0, m = 0;  vector<long long> C(n), B(n), T;
	C[0] = B[0] = 1;  long long b = 1;
	for (int i=0; i<n; i++) {
		++m;  long long d = s[i] % mod;
		for (int j=1; j<=L; j++) d = (d + C[j]*s[i-j]) % mod; // chosen mod = 5
		if (!d) continue;
		T = C;  long long coef = d * fastExp(b, mod-2) % mod;
		for (int j=m; j<=n-1; j++) C[j] = (C[j] - coef*B[j-m]) % mod;
		if (2*L > i) continue;
		L = i + 1 - L;  B = T;  b = d;  m = 0;
	}
	C.resize(L+1);  C.erase(C.begin());
	for (auto& x: C) x = (mod-x) % mod;  return C;
}
