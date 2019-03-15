const int OO =(int)1e9;  const ll INF =(ll)1e18;
int getint(){ int x;  scanf("%d",&x);  return x; }
const int MAXN =512;
int A[MAXN];  int na;  int B[MAXN];  int nb;
int prev[MAXN][MAXN];
ll best[MAXN][MAXN];
int pos[MAXN][MAXN];

void printPath(int path){
	if(prev[path>>10][path&1023] == -1)
		printf("%d",A[path>>10]);
	else{
		printPath(prev[path>>10][path&1023]);
		printf(" %d",A[path>>10]);
}	}
int main(){
	FOR(i,na=getint())A[i] = getint();
	FOR(i,nb=getint())B[i] = getint();
	FOR(i,nb) FOR(j,nb)best[i][j] = INF;
	FOR(i,na) FOR(j,nb)prev[i][j] = -1;
	FOR(i,na){
		int x = -1, p =0;
		FOR(j,nb){
			if(A[i] == B[j]){
				int y = p;  while(best[j][y]<A[i])y++;
				best[j][y] = A[i];  pos[j][y] = (i<<10)+j;
				if(y >0)prev[i][j] = pos[j][y-1];
				x = p = y;
			} else if(x!=-1 && best[j-1][x]<best[j][x]){
				best[j][x] = best[j-1][x];
				pos[j][x] = pos[j-1][x];
			} else x = -1;
	}   }
	int len = -1;
	FORD(i,nb) if(best[nb-1][i]!=INF){
		len=i;  break;
	}
	printf("%d\n",len+1);
	if(len >=0)printPath(pos[nb-1][len]);  puts("");
}