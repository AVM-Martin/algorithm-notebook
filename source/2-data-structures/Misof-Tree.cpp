class KthTree {
private:
	int** tree, nlv;
	int lv(int n, int ret = 0) { while ((1<<ret)<=n) ret++;  return ret; }
public:
	KthTree(int n) {
		this->nlv = this->lv(n) + 1;
		tree = (int**)malloc(sizeof(int*) * (this->nlv));
		for (int i=0; i<(this->nlv); i++) {
			tree[i] = (int*)malloc(sizeof(int) * (1 << (this->nlv - 1)));
			memset(tree[i], 0, sizeof(int) * (1 << (this->nlv - 1)));
	}	}
	~KthTree() {
		for (int i=0; i<(this->nlv); i++) free(tree[i]);
		free(tree);
	}
	void insert(int n) {
		for (int i=0; i<(this->nlv); i++) tree[i][n]++, n >>= 1;
	}
	void erase(int n){
		for (int i=0; i<(this->nlv); i++) tree[i][n]--, n >>= 1;
	}
	int KthElement(int k){
		int a = 0, b = (this->nlv) - 1;
		while (b--) if (tree[b][a<<=1] < k) k -= tree[b][a++];
		return a;
	}
};
