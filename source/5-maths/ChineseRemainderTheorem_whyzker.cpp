//CRT Willson
int inv(int a, int m){
	int m0 = m, t, q, x0 = 0, x1 = 1;  if(m == 1) return 0;
	while(a > 1) q=a/m, t=m, m=a%m, a=t, t=x0, x0 = x1 - q*x0, x1=t;
	return x1 + (x1 < 0)*m0; // Make x1 positive
}
// k is size of num[] and rem[]. Returns the smallest number x that
//    x % num[0]   = rem[0]
//    x % num[1]   = rem[1]
//    ..................
//    x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
int findMinX(int num[], int rem[], int k){
	int prod = 1, res = 0;  FOR(i,k) prod *= num[i];
	FOR(i,k) res += rem[i] * inv(prod/num[i],num[i]) * (prod/num[i]);
	return res % prod;
}
// driver
int num[] = {3, 4, 5}, rem[] = {2, 3, 1}, k = 3;
cout << "x is "<< findMinX(num, rem, k);