void getZarr(string str) {
	int n = str.length(), L = 0, R = 0, k;
	for (int i=1; i<=n-1; i++) {
		if (i > R) {
			L = R = i;  while (R<n && str[R-L] == str[R]) R++;
			Z[i] = R-L;  R--;
		} else {
			k = i-L;
			if (Z[k] < R-i+1) Z[i] = Z[k];
			else {
				L = i;  while (R<n && str[R-L] == str[R]) R++;
				Z[i] = R-L;  R--;
}	}	}	}
