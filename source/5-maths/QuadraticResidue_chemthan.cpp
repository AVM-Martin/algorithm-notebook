// Source: https://github.com/chemthan/chemthan
// Desc  : Find x such that (x * x) % mod == a
// Time  :
// Status:
const int MAXN = 1e5 + 5;  int qn[MAXN];
long long calc(long long a, long long mod) {
	if (fastExp(a, (mod - 1) / 2, mod) != 1) return -1;
	if (mod % 4 == 3) return fastExp(a, (mod + 1) / 4, mod);
	long long q = mod - 1, s = 0, z = 1;  for (; q % 2 == 0; q /= 2) s++;
	if (qn[mod]) z = qn[mod];
	else while (fastExp(z, (mod - 1) / 2, mod) != mod - 1) qn[mod] = (z += 1);
	long long c = fastExp(z, q, mod), r = fastExp(a, (q + 1) / 2, mod);
	long long t = fastExp(a, q, mod), m = s;
	while (1) {
		if (t == 1) return r;
		int i = 1;  long long tmp = t;
		for (; i < m; i++) if ((tmp = (tmp * tmp) % mod) == 1) break;
		long long b = c, x = m - i - 1;
		for (; x > 0; x--) b = (b * b) % mod;
		r = (r * b) % mod;  t = (((t * b) % mod) * b) % mod;
		c = (b * b) % mod;  m = i;
}	}
