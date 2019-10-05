double memo[11000];
void start(){
	memo[1] = log10(1);
	REP(i,2,10000) memo[i] = memo[i-1] + (double)log10(i);
}
int solve(int n){ return (int)memo[n] + 1; }
