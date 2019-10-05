int m,n, L2R[max_man], R2L[max_woman], p[max_man];
int L[max_man][max_woman], R[max_woman][max_man];
void stableMarriage(){
	static int p[128];
	memset(R2L,-1,sizeof(R2L));  memset(p,0,sizeof(p));
	FOR(i,m) for(int man=i,hubby; man>=0; man=hubby){
		int wom;
		while(1){
			wom = L[man][p[man]++];
			if(R2L[wom]<0 || R[wom][man] > R[wom][R2L[wom]]) break;
		}
		hubby = R2L[wom];  R2L[L2R[man]=wom] = man;
}	}
