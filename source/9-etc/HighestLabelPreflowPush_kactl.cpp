// Source: https://github.com/kth-competitive-programming/kactl/
// Desc  : Push-relabel using the highest label selection rule and
//         the gap heuristic. Quite fast in practice. To obtain the
//         actual flow, look at positive values only.
// Time  : O(V^2 sqrt E)
// Status: Tested on kattis and SPOJ
typedef ll Flow;
struct Edge{ int dest, back;  Flow f, c; };
struct PushRelabel{
	vector<vector<Edge>> g;  vector<Flow> ec;  vector<Edge*> cur;
	vector<vi> hs;   vi H;
	//
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}
	void add_edge(int s, int t, Flow cap, Flow rcap=0){
		if(s == t) return;
		Edge a = {t, (int)g[t].size(), 0, cap};
		Edge b = {s, (int)g[s].size(), 0, rcap};
		g[s].pb(a);  g[t].pb(b);
	}
	void add_flow(Edge& e, Flow f){
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].pb(e.dest);
		e.f += f;  e.c -= f;  ec[e.dest] += f;
		back.f -= f;  back.c += f;  ec[back.dest] -= f;
	}
	Flow maxflow(int s, int t){
		int v = (int)g.size();  H[s] = v;  ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		FOR(i,v) cur[i] = g[i].data();
		for(auto& e: g[s]) add_flow(e, e.c);
		for(int hi = 0; ; ){
			while(hs[hi].empty()) if(!hi--) return -ec[s];
			int u = hs[hi].back();  hs[hi].pob();
			while(ec[u] > 0){ // discharge u
				if(cur[u] == g[u].data() + sz(g[u])){
					H[u] = 1e9;
					for(auto& e: g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						FOR(i,v) if(hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if(cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
}	}	}	};