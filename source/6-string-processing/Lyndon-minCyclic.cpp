// Source: https://cp-algorithms.com/string/lyndon_factorization.html
// Source: https://github.com/stjepang/snippets/blob/master/min_rotation.cpp
// Desc  : Find a minimum cyclic string rotation
// Time  : O(N)
// Status: Fuzz-tested
int min_cyclic_string(char s[], int n) {
	for (int i=0; i<n; i++) s[n+i] = s[i];
	int res = 0;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
		if (res + j == i || s[res+j] < s[i+j]) { i += max(0, j-1); break; }
		if (s[res+j] > s[i+j]) { res = i; break; }
	} return res;
}
vector<string> duval(char s[], int n) {
	vector<string> factors;  int res = 0;
	for (int i=0; i<n; ) { // s += s with i < half for min cyclic
		res = i;  int j = i + 1, k = i;
		for (; j < n && s[k] <= s[j]; j++) k = (s[k] < s[j] ? i : k + 1);
		for (; i <= k; i += j - k) factors.push_back(s.substr(i, j - k));
	} return factors; // return s[res:res+half] for min cyclic
}
