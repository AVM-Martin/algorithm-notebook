class KthTree{
	private:
		int**tree, nlv;  int lv(int);
	public:
		KthTree(int);
		~KthTree();
		void insert(int);
		void erase(int);
		int KthElement(int);
};
int KthTree::lv(int n, int ret = 0){
	while((1<<ret)<=n)ret++;  return ret;
}
KthTree::KthTree(int n){
	this->nlv = this->lv(n) + 1;
	tree=(int**)malloc(sizeof(int*)*(this->nlv));
	FOR(i,this->nlv){
		tree[i] = (int*)malloc(sizeof(int) * \
				(1<<(this->nlv-1)));
		memset(tree[i], 0, sizeof(int) * \
				(1<<(this->nlv-1)));
	}
}
KthTree::~KthTree(){
	FOR(i,this->nlv)free(tree[i]);  free(tree);
}
void KthTree::insert(int n){
	FOR(i,this->nlv)tree[i][n]++, n >>= 1;
}
void KthTree::erase(int n){
	FOR(i,this->nlv)tree[i][n]--, n >>= 1;
}
int KthTree::KthElement(int k){
	int a =0, b = (this->nlv)-1;
	while(b--) if(tree[b][a<<=1]<k)k -= tree[b][a++];
	return a;
}