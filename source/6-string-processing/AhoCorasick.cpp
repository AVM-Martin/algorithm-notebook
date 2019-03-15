struct Trie{
	Trie *next[52], *fail;  vi label;  bool match;
	Trie(){
		fail = NULL;  match = false;  label.clear();
		memset(next,0,sizeof(next));
}	};
void build_Trie(Trie** a, int val){
	int len = strlen(q_in);  Trie *p = *a;
	FOR(w,len){
		int idx = convert(q_in[w]);
		if(p->next[idx] == NULL)
			p->next[idx] = new Trie();
		p = p->next[idx];
	}
	p->label.pb(val);
}
void build_Automation(Trie* root){
	queue<Trie*> q;  Trie *state, *fail;
	root->fail = NULL;  q.push(root);
	while(!q.empty()){
		state = q.front();  q.pop();
		FOR(a,52){
			if(state->next[a] == NULL) continue;
			q.push(state->next[a]);
			fail = state->fail;
			while(fail!=NULL && fail->next[a]==NULL)
				fail = fail->fail;
			if(fail == NULL)state->next[a]->fail = root;
			else state->next[a]->fail = fail->next[a];
}	}	}
void search_pattern(Trie* root){
	Trie *p = root, *check;
	int len = strlen(main_in);
	FOR(a,len){
		int nx = convert(main_in[a]);
		while(p!=root && p->next[nx]==NULL)
			p = p->fail;
		p = p->next[nx];
		if(p == NULL)p = root;
		check = p;
		while(check!=root && check->match==false){
			int sz = check->label.size();
			FOR(b,sz)mark[check->label[b]] = true;
			check->match = true;  check = check->fail;
}	}	}
void clear_Automation(Trie* root){
	queue<Trie*> q;  Trie *nx;  q.push(root);
	while(!q.empty()){
		nx = q.front();  q.pop();
		FOR(a,52) if(nx->next[a] != NULL)
			q.push(nx->next[a]);
		nx->label.clear();  delete nx;
}	}