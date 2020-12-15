template<typename T> T MOD(T a, T b) { return ((a % b) + b) % b; }
template<typename T> pair<T,T> CRT(T a, T n, T b, T m) {
	T _n, _m;  T gcd = Euclid(n, _n, m, _m);
	if (n == m) return (a == b) ? pair<T,T>(a, n) : pair<T,T>(-1, -1);
	else if (abs(a - b) % gcd != 0) return pair<T,T>(-1, -1);
	else {
		T lcm = m * n / gcd;
		T x = MOD(a + MOD(n * MOD(_n * ((b-a)/gcd), m / gcd), lcm), lcm);
		return pair<T,T>(x, lcm);
}	} // return x, lcm. x = a % n && x = b % m
