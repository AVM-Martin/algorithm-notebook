// construct a trie containing all patterns using this Node
class Node{ public: int idx, ptr[52], fail, jump; };
// aho corasick helper
int __fail(int idx, int idxChild, int repeat=0){
	if(repeat == 1) return idx;
	if(dat[idx].ptr[idxChild] != 0) return dat[idx].ptr[idxChild];
	return __fail(dat[idx].fail, idxChild, idx==dat[idx].fail);
}
inline int __suffixLink(int idx){
	return (dat[idx].idx != 0) ? idx : dat[idx].jump;
}
// aho corasick, build process by layer
inline void ahoCorasick(){
	queue<int> bfs; while(!bfs.empty()) bfs.pop();
	//construct root first
	dat[1].fail = dat[1].jump = 1;  bfs.push(1);
	while(!bfs.empty()){
		int idx = bfs.front(); bfs.pop();
		//construct its children
		FOR(i,52) if(dat[idx].ptr[i] != 0){
			int next = dat[idx].ptr[i];
			dat[next].fail = __fail(dat[idx].fail, i, (idx==1));
			dat[next].jump = __suffixLink(dat[next].fail);
			bfs.push(next);
}	}	}
