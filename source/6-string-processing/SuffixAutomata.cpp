struct state { int len,link,cnt;  int nx[26]; } st[MAX<<1];
int id,last,cur,clone;  vector<int> v[MAX];
inline void sa_init() {
	st[0].link = -1;  mems(st[0].nx,0);  id = last = st[0].cnt = 0;
}
inline void sa_extend(int c){
	st[last].nx[c] = cur = ++id;  st[cur].len = st[last].len + 1;
	v[st[cur].len].pb(cur);  st[cur].cnt = 1;  int p = last;
	while (1) {
		if ((p = st[p].link) == -1) { st[cur].link = 0; break; }
		if (st[p].nx[c]) {
			int q = st[p].nx[c];
			if (st[p].len + 1 == st[q].len) st[cur].link = q;
			else {
				clone = ++id;  st[clone] = st[q];
				st[clone].cnt = 0;  st[clone].len = st[p].len+1;
				v[st[clone].len].pb(clone);  st[q].link = st[cur].link = clone;
				while (p != -1 && st[p].nx[c] == q) {
					st[p].nx[c] = clone;  p = st[p].link;
			}	}
			break;
		} else st[p].nx[c] = cur;
	}
	// online tapi TLE :p
	// p = st[cur].link;  while (p != -1) ++st[p].cnt, p = st[p].link;
	last = cur;
}
int inside_main() {
	for (int i=(int)s.size(); i>=1; i--) for (int j: v[i]) {
		st[st[j].link].cnt += st[j].cnt;
}	}
inline int lcs(string &s, string &t) {
	sa_init();  for (char c: s) sa_extend(c - 'a');
	int best = 0, len = 0; cur = 0;
	for (char c: t) {
		c -= 'a';
		while (cur && !st[cur].nx[c]) cur = st[cur].link, len = st[cur].len;
		if (st[cur].nx[c]) { cur = st[cur].nx[c];  best = max(best, ++len); }
	} return best;
}
