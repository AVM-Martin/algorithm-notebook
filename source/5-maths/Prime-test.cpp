const int MAX = (int)1e8, HALF = (int)5e7, SQRT = 5000;
const int SIZE = MAX/16+2;  char SITO[SIZE];
#define NTH(n) ((n)&7)
#define ISPRIME(n) (SITO[(n)>>4]&(1<<NTH((n)>>1)))

bool isPrime(int n){ return (n%2==0) ? (n==2) : ISPRIME(n); }
// init
FILL(SITO,0xFF);  SITO[0] = 0xFE;
REP(i,1,SQRT-1) if(ISPRIME(i<<1)) REPP(j,2*i*(i+1),HALF-1,2*i+1)
	SITO[j>>3] &= ~(1 << NTH(j));