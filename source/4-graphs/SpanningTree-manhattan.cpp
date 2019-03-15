const int INF =(int)1e9;
struct Pos{ int x,y, diff,sum, id; } p[150000];
vi BIT;  vector<pair<pair<int,int>,int>> Raw_Edges;

bool sortpoint(Pos A, Pos B){
	if(A.x != B.x)return A.x > B.x;
	return A.y > B.y;
}
int GetNearest(int x){
	int ret =-1;
	for(; x>0; x-=(x&(-x)))
		if(BIT[x]!=-1&&(ret==-1 || \
			p[BIT[x]].sum < p[ret].sum)) ret = BIT[x];
	return ret;
}
void Insert(int x,int id){
	int maxi = BIT.size();
	for(; x<maxi; x+=(x&(-x)))
		if(BIT[x]==-1 || (p[id].sum<p[BIT[x]].sum))
			BIT[x] = id;
}
void AddEdges(){
	viaxis;  axis.pb(-INF);
	FOR(a,n)axis.pb(p[a].diff);
	sort(axis.begin(),axis.end());
	axis.erase( unique(axis.begin(),axis.end()), \
		axis.end() );
	sort(p, p+n, sortpoint);
	BIT = vi(axis.size(),-1);
	FOR(a,n){
		int pos = lower_bound(axis.begin(), \
			axis.end(), p[a].diff) - axis.begin();
		int nearest = GetNearest(pos);
		if(nearest != -1) Raw_Edges.pb(mp(mp(p[a].id, \
			p[nearest].id),p[nearest].sum - p[a].sum));
		Insert(pos,a);
}	}
int main(){
	FOR(a,n){
		scanf("%d%d",&p[a].x,&p[a].y);
		p[a].sum = p[a].x + p[a].y;
		p[a].diff = p[a].x - p[a].y;  p[a].id = a;
	}
	FOR(a,4){
		FOR(b,n){
			if(a==1 || a==3){
				swap(p[b].x,p[b].y);
				p[b].diff = p[b].x - p[b].y;
			} else if(a==2){
				p[b].x =-p[b].x;
				p[b].sum = p[b].x + p[b].y;
				p[b].diff = p[b].x - p[b].y;
			}
		} AddEdges();
	}
	//DO MST
}