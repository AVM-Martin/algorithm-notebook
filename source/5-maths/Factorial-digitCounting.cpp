double memo[11000];
void start() {
	memo[1] = log10(1);
	for (int i=2; i<=10000; i++) memo[i] = memo[i-1] + (double)log10(i);
}
int solve(int n) { return (int)memo[n] + 1; }
