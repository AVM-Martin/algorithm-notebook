// Given array A[] of 2^N integers, find sum of all F(x),
// where F(x) = sum of all A[i] where x&i=i

// O(3^N)      iterate over all the masks
FOR(mask,(1<<N)){
	F[mask] = A[0];
    for(int i=mask; i; i=(i-1)&mask) F[mask] += A[i];
}
// O(N * 2^N)  memory optimized, easy to code.
FOR(i,(1<<N)) F[i] = A[i];
FOR(i,N) FOR(mask,(1<<N)) if(mask&(1<<i)) F[mask] += F[mask^(1<<i)];