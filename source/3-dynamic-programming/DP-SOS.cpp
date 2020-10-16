// Given array A[] of 2^N integers, find sum of all F(x),
// where F(x) = sum of all A[i] where x & i == i

// O(3^N)      iterate over all the masks
for (int mask=0; mask<(1<<N); mask++) {
	F[mask] = A[0];
	for (int i=mask; i; i=(i-1)&mask) F[mask] += A[i];
}
// O(N * 2^N)  memory optimized, easy to code.
for (int mask=0; mask<(1<<N); mask++) F[mask] = A[mask];
for (int i=0; i<N; i++) for(int mask=0; mask<(1<<N); mask++) if (mask&(1<<i)) {
	F[mask] += F[mask^(1<<i)];
}
