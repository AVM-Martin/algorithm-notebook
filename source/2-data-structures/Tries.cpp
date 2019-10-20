typedef struct {
	char kar;  bool isWord;  int parent;  map<char,int> child;
} node;

char s[100];  node tree[2000001];  int idx, len, nn, ma;

void insert(int nodeIdx, int charIdx) {
	if (tree[nodeIdx].child.count(s[charIdx]) == 0) {
		tree[++idx].kar = s[charIdx];
		tree[idx].parent = nodeIdx;
		tree[idx].child.clear();
		tree[nodeIdx].child[s[charIdx]] = idx;
	}
	if(charIdx == len-1) tree[tree[nodeIdx].child[s[charIdx]]].isWord = 1;
	else insert(tree[nodeIdx].child[s[charIdx]], cIdx+1);
}
void traverse(int x, int depth) {
	depth += tree[x].isWord;
	if (ma < depth) ma = depth, nn = x;
	for (auto i: tree[x].child) traverse(i.se,depth);
}
int main() {
	idx = 0;  tree[0].kar=0;  ma=-1;
	while (scanf("%s",s)) {
		if (strcmp(s,".") == 0) break;
		len = strlen(s);  insert(0,0);
	}
	nn = 0;  traverse(0,0);
	int res[100], dd = 0;  char ss[100];
	while (nn) {
		ss[dd] = tree[nn].kar;
		res[dd++] = tree[nn].isWord;
		nn = tree[nn].parent;
	}
	reverse(ss,ss+dd);  reverse(res,res+dd);  ss[dd]=0;
	for (int i=0; i<dd; i++) if (res[i]) {
		char temp = ss[i+1];  ss[i+1] = 0;
		printf("%s\n", ss);  ss[i+1] = temp;
}	}
// Input   :   i if in input int integer output
// Output  :   i in int integer

// Another trie
#define MA 5000010
typedef struct Tnode { int counter;  char p;  int child[3]; } node;

char s[210];  node trie[MA];  int idx,len,res;

void insert(int trid, int id) {
	trie[trid].counter++;
	if (id == len) return;
	if (trie[trid].child[s[id]-'0'] == -1) {
		trie[++idx].p = s[id];
		trie[trid].child[s[id]-'0'] = idx;
	}
	insert(trie[trid].child[s[id]-'0'], id+1);
}
void calc(int idx, int length) {
	res = max(res, trie[idx].counter * length);
	if(trie[idx].child[0] != -1) calc(trie[idx].child[0], length+1);
	if(trie[idx].child[1] != -1) calc(trie[idx].child[1], length+1);
}
int main() {
	int t,n;  scanf("%d",&t);
	while (t--) {
		idx = 0;  scanf("%d",&n);
		for (int i=0; i<MA; i++) {
			trie[i].counter = 0;
			trie[i].child[0] = trie[i].child[1] = -1;
		}
		while (n--) { scanf("%s", s);  len = strlen(s);  insert(0,0); }
		res = 0;  calc(0,0);  printf("%d\n", res);
}	}
