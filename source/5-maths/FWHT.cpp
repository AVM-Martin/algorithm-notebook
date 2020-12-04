// OP  => c00 c01 c10 c11 | c00 c01 c10 c11 inv
// XOR =>  +1  +1  +1  -1 |  +1  +1  +1  -1 | div the inverse with size = n
// AND =>   0   1   1   1 |  -1  +1  +1  +0 | no comment
//  OR =>   1   0   1   1 |  +1  +0  -1  +1 | untested
typedef vector<long long> vec;
void FWHT(vec& a) {
	int n = a.size();
	for (int lvl=1; 2*lvl<=n; lvl<<=1) {
		for (int i=0; i<n; i+=2*lvl) {
			for (int j=0; j<lvl; j++) {
				long long u = a[i + j], v = a[i + lvl + j];
				a[i + j]       = u + v; // c00 * u + c01 * v
				a[i + len + j] = u - v; // c10 * u + c11 * v
}	}	}	}  // you can convolve as usual
