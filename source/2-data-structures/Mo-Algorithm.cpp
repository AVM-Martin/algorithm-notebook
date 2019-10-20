typedef pair< pair<int,int> , int > iii;

int blocks, ans, answer[300100], cnt[1000100], a[300100];
vector<iii> v;

bool cmp(iii x, iii y) {
	if (x.first.first / blocks == y.first.first / blocks) {
		return x.first.second < y.first.second;
	}
	return x.first.first / blocks < y.first.first / blocks;
}
void add(int position) { if (++cnt[a[position]] == 1) ans++; }
void remove(int position) { if (--cnt[a[position]] == 0) ans--; }
int main() {
	int n;  scanf("%d",&n);  blocks = (int)sqrt(n);
	for (int i=0; i<n; i++) scanf("%d",&a[i]);
	int q;  scanf("%d",&q);
	for (int i=0; i<q; i++) {
		int l,r;  scanf("%d %d", &l, &r);
		v.push_back( make_pair(make_pair(l-1,r-1), i) );
	}
	sort(v.begin(), v.end(), cmp);
	int currentL = 0, currentR = -1;
	for (int i=0; i<(int)v.size(); i++) {
		int l = v[i].fi.fi, r = v[i].fi.se, idx = v[i].se;
		while (currentR < r) add(++currentR);
		while (currentR > r) remove(currentR--);
		while (currentL < l) remove(currentL++);
		while (currentL > l) add(--currentL);
		answer[idx] = ans;
	}
	for (int i=0; i<q; i++) printf("%d\n", answer[i]);
}
