// Desc  : Prime Checking with num-1 = (2^r)*d and witness a = random[2..num-1)
// Time  : O(iteration * log(N)^2) up to O(iteration * log(N))
// Status: stress test 1e8 + SPOJ PON
const long long witness[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
bool isProbablyPrime(long long num, long long r, long long d, long long a) {
	a = fastExp(a % num, d, num);  if (a == 1) return true;
	for (int i=0; i<r && a != num - 1; i++) if (i) a = multiply(a, a, num);
	return a == num - 1;
}
bool isPrime(long long num, int iteration = 100) {
	if (num <= 3) return (num != 1);
	long long d = num - 1, r = 0;  while (d % 2 == 0) d >>= 1, r++;
	for (int i=0; i<13; i++) { // iteration
		long long a = witness[i]; // (long long)2 + (rand() % (num - 3))
		if (a < num && isProbablyPrime(num, r,d, a) == false) return false;
	} return true;
}
