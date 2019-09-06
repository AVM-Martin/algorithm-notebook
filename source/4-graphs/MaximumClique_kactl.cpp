// Source: https://github.com/kth-competitive-programming/kactl/
// Desc  : Runs a callback for all maximal cliques in a graph (given
//         as a symmetric bitset matrix; self-edges not allowed).
// Optim : on the top-most recursion level, ignore 'cands', and go
//         through nodes in order of increasing degree, where degrees go
//         down as nodes are removed.
// Time  : O(3^{n/3}), much faster for sparse graphs
// Status: fuzz-tested
typedef bitset<128> B;
template<class F>
void cliques(vector<B>& eds, F f, B P = ~B(), B X={}, B R={}) {
	if(!P.any()){ if(!X.any()) f(R);  return; }
	auto q = (P | X)._Find_first();  auto cands = P & ~eds[q];
	FOR(i,(int)eds.size()) if(cands[i]){
		R[i] = 1;  cliques(eds, f, P & eds[i], X & eds[i], R);
		R[i] = P[i] = 0; X[i] = 1;
}	}
