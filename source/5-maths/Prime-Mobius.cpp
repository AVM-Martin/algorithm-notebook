int M[MAXN];   // M=mobius
int SPF[MAXN]; // SPF=smallest pf
bool B[MAXN];  vi prima; // B=is prime

void mobius(){
	prima.clear();  memset(B,true,sizeof(B));
	B[0] = B[1] = false;
	REP(i,2,MAXN-1){
		if(B[i])prima.pb(i), SPF[i] = i;
		FOR(auto j: prima){
			if(!(i*j<MAXN && j<=SPF[i]))break;
			B[i*j] = false;  SPF[i*j] = j;
	}	}
	REP(i,1,MAXN-1){
		if(i == 1)M[i]=1;
		else if(SPF[i] == i)M[i] = -1;
		else if((i/SPF[i])%SPF[i] == 0)M[i] = 0;
		else M[i] = M[i/SPF[i]]*M[SPF[i]];
}	}