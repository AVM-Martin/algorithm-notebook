const int INF =(int)1e9;
struct Pos { int x,y, diff,sum, id; } p[150000];
vector<int> BIT;  vector<pair<pair<int,int>,int>> Raw_Edges;

bool sortpoint(Pos A, Pos B) { return (A.x != B.x) ? A.x > B.x : A.y > B.y; }
int GetNearest(int x) {
	int ret = -1;
	for (int i=x; i>=1; i-=LSOne(i)) {
		if (BIT[i] != -1 && (ret == -1 || p[BIT[i]].sum < p[ret].sum)) {
			ret = BIT[i];
	}	}
	return ret;
}
void Insert(int x, int id) {
	for (int i=x; i<=(int)BIT.size()-1; i+=LSOne(i)) {
		if (BIT[i] == -1 || p[id].sum < p[BIT[i]].sum) BIT[i] = id;
	}
}
void AddEdges() {
	vector<int> axis;  axis.push_back(-INF);
	for (int a=0; a<n; a++)  axis.push_back(p[a].diff);
	sort(axis.begin(), axis.end());
	axis.erase( unique(axis.begin(),axis.end()), axis.end() );
	sort(p, p+n, sortpoint);
	BIT = vector<int>(axis.size(), -1);
	for (int a=0; a<n; a++) {
		int pos = lower_bound(axis.begin(), axis.end(), p[a].diff) - axis.begin();
		int nearest = GetNearest(pos);
		if (nearest != -1) Raw_Edges.push_back(make_pair(
			make_pair(p[a].id, p[nearest].id),
			p[nearest].sum - p[a].sum
		));
		Insert(pos, a);
}	}
// inside main()
for (int a=0; a<n; a++) {
	scanf("%d %d", &p[a].x, &p[a].y);
	p[a].sum  = p[a].x + p[a].y;  p[a].diff = p[a].x - p[a].y;  p[a].id = a;
}
for (int a=0; a<4; a++) {
	for (int b=0; b<n; b++) {
		if (a == 1 || a == 3) {
			swap(p[b].x, p[b].y);  p[b].diff = p[b].x - p[b].y;
		} else if (a == 2) {
			p[b].x = -p[b].x;
			p[b].sum  = p[b].x + p[b].y;
			p[b].diff = p[b].x - p[b].y;
	}	}
	AddEdges();
}
// DO MST
