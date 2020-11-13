// Source: https://codeforces.com/contest/106/submission/9237081
// Desc  : Find a minimum enclosing circle radius
// Time  : O(ITERATION * N)
// Status: CF 106E
// X is average of xi, Y is average of yi, Z is average of zi
double P = 0.1;
for (int xxx = 0; xxx < ITERATION; xxx++) {
	int idx = 1;  double ret = dist(X - x[1], Y - y[1], Z - z[1]);
	for (int i = 2; i <= n; i++) {
		double temp = dist(X - x[i], Y - y[i], Z - z[i]);
		if (ret < temp) { ret = temp;  idx = i; }
	}
	X += (x[idx] - X) * P;  Y += (y[idx] - Y) * P;  Z += (z[idx] - Z) * P;
	P *= 0.998;
}
// center is on (X, Y, Z)
