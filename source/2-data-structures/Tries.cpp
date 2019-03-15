typedef struct{
	char kar;  bool isWord;  int parent;
	map<char,int> child;
} node;
char s[100];  node tree[2000001];
int idx,len,nn,ma;

void insert(int nIdx, int cIdx){ //nodeIdx,charIdx
	if(tree[nIdx].child.count(s[cIdx])==0){
		tree[++idx].kar = s[cIdx];
		tree[idx].parent = nIdx;
		tree[idx].child.clear();
		tree[nIdx].child[s[cIdx]] = idx;
	}
	if(cIdx == len-1)
		tree[tree[nIdx].child[s[cIdx]]].isWord=1;
	else insert(tree[nIdx].child[s[cIdx]],cIdx+1);
}
void traverse(int x, int depth){
	depth += tree[x].isWord;
	if(ma < depth)ma = depth, nn = x;
	for(auto i: tree[x].child)traverse(i.se,depth);
}
int main(){
	idx = 0;  tree[0].kar=0;  ma=-1;
	while(scanf("%s",s)){
		if(strcmp(s,".") == 0)break;
		len = strlen(s);
		insert(0,0);
	}
	nn = 0;
	traverse(0,0);
	int res[100], dd = 0;  char ss[100];
	while(nn){
		ss[dd] = tree[nn].kar;
		res[dd++] = tree[nn].isWord;
		nn = tree[nn].parent;
	}
	reverse(ss,ss+dd);  reverse(res,res+dd);
	ss[dd]=0;
	FOR(i,dd) if(res[i]){
		char temp = ss[i+1];  ss[i+1] = 0;
		printf("%s\n",ss);  ss[i+1] = temp;
}	}
// Input   :   i if in input int integer output
// Output  :   i in int integer

// Another trie
#define MA 5000010
typedef struct Tnode{
	int counter;  char p;  int child[3];
} node;
char s[210];  node trie[MA];  int idx,len,res;

void insert(int trid, int id){
	trie[trid].counter++;
	if(id == len)return;
	if(trie[trid].child[s[id]-'0']==-1){
		trie[++idx].p = s[id];
		trie[trid].child[s[id]-'0'] = idx;
	}
	insert(trie[trid].child[s[id]-'0'],id+1);
}
void calc(int idx, int length){
	res = max(res,trie[idx].counter * length);
	if(trie[idx].child[0] != -1)
		calc(trie[idx].child[0],length+1);
	if(trie[idx].child[1] != -1)
		calc(trie[idx].child[1],length+1);
}
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		idx = 0;
		scanf("%d",&n);
		FOR(i,MA){
			trie[i].counter = 0;
			trie[i].child[0] = trie[i].child[1]=-1;
		}
		while(n--){
			scanf("%s", s);  len = strlen(s);
			insert(0,0);
		}
		res = 0;  calc(0,0);  printf("%d\n",res);
}	}