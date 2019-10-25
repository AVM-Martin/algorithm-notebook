int M[MAXN], SPF[MAXN];  // M = mobius, SPF = smallest pf
bool B[MAXN];  vi prima; // B = is prime
void mobius() {
	prima.clear();  memset(B, true, sizeof(B));  B[0] = B[1] = false;
	for (int i=2; i<=MAXN-1; i++) {
		if (B[i]) prima.push_back(i), SPF[i] = i;
		for (auto j: prima) {
			if (!(i*j < MAXN && j <= SPF[i])) break;
			B[i*j] = false;  SPF[i*j] = j;
	}	}
	for (int i=1; i<=MAXN-1; i++) {
		if (i == 1) M[i]=1;
		else if (SPF[i] == i) M[i] = -1;
		else if ((i/SPF[i]) % SPF[i] == 0) M[i] = 0;
		else M[i] = M[i/SPF[i]] * M[SPF[i]];
}	}
