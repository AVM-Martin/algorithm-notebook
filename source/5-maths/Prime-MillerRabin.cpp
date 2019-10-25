// num-1 = (2^r)*d, a = random[2..num-2] as witness number
bool isProbablyPrime(long long a) { // remember: a is witness number
	a = fast(a,d,num);  if (a == 1) return true;
	for (int i=0; i<r; i++) {
		if (i) a = multiply(a,a,num);
		if (a == num-1) return true;
	}
	return false;
}
bool isPrime(long long num, int iteration, bool res = true) {
	long long d = num-1, r = 0;  while (d%2 == 0) d >>= 1, r++;
	for (int i=0; i<iteration; i++) res &= isProbablyPrime(a);
	return res;
}
