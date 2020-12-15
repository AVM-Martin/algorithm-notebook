// Source: https://cp-algorithms.com/others/josephus_problem.html#toc-tgt-3
// Source: https://en.wikipedia.org/wiki/Josephus_problem#Bitwise
// Time  : O(K log N)
// Status: https://codeforces.com/gym/102409/problem/D
long long josephus(long long n, long long k) { // zero based
	if (n == 1) return 0;
	if (k == 1) return n - 1;
	if (k == 2) { // f(N) = 2L where N = 2^M + L and 0 <= L < 2^M
		long long two = 1; while (two < n) two <<= 1;
		return ~two & (n << 1);
	}
	if (k > n) return (josephus(n-1, k) + k) % n;
	long long res = josephus(n - n / k, k) - (n % k);
	return res + (res < 0 ? n : res / (k - 1));
}
