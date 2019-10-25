// this function returns the sum of the divisors of n. i.e div(3)
// will return sum of the number of divisors up to 3.
long long div(int n) {
	if (n == 0) return 0;
	long long res = 0, i;  for (i=2; i<=n/i; i++) res += n/i;
	i--;  res = (n*2) - (i*i) + (res*2);  return res;
}
