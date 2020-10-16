// WQS Binary Search Optimization (Monge)
// Recurrence : dp[i][j] = min{ dp[i-1][j], dp[i-2][j-1] + a[i] }
// Condition  : F(x+1) - F(x) <= F(x+2) - F(x+1) with F(x) = dp[n][x]
// Method     : find min G(x) = F(x) - x*C with C is the key
// Transition : dp[i] = min{ dp[i-2] + a[i] - C }
// from O(nk) become O(n log n)
int left = min_diff, right = max_diff, mid, gval, slope;
while (left <= right) {
	int mid = (left + right) / 2;
	int cnt = solve(mid);
	if (cnt <= key) {
		slope = mid;
		gval = G(opt); // from dp[n] inside solve()
		left = mid + 1;
	} else {
		right = mid - 1;
}	}
int inside_main() { cout << gval + k * slope << endl;}
