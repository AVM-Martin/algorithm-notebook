class AVL {
	struct Node {
		char data[15];
		char key[15];
		Node *l, *r;
		int h;
	};

	Node* root = NULL;

	int getH(Node* curr) {
		return (curr == NULL) ? 0 : curr->h;
	}

	Node* newNode(const char _key[], const char _data[]) {
		Node* rett = (Node*)malloc(sizeof(Node));

		strcpy(rett->key, _key);
		strcpy(rett->data, _data);
		rett->l = rett->r = NULL;
		rett->h = 1;

		return rett;
	}
	Node* delNode(Node* curr) {
		free(curr);
		return NULL;
	}

	Node* search(Node* curr, const char _key[]) {
		if (curr == NULL) {
			return NULL;
		} else if (strcmp(_key, curr->key) < 0) {
			return search(curr->l, _key);
		} else if (strcmp(_key, curr->key) == 0) {
			return curr;
		} else if (strcmp(_key, curr->key) > 0) {
			return search(curr->r, _key);
		}
	}

	Node* getLeftmost(Node* curr) {
		if (curr->l == NULL) return curr;
		return getLeftmost(curr->l);
	}

	Node* rotL(Node* curr) {
		Node* temp = curr;  /*    curr         z    */
		curr = curr->r;     /*    /  \        /     */
		temp->r = curr->l;  /*   y    z    curr     */
		curr->l = temp;     /*       /     /  \     */
		// update height    /*      T     y    T    */
		temp->h = max(getH(temp->l), getH(temp->r)) + 1;
		curr->h = max(getH(curr->l), getH(curr->r)) + 1;
		return curr;
	}
	Node* rotR(Node* curr) {
		Node*temp = curr;   /*    curr     y        */
		curr = curr->l;     /*    /  \      \       */
		temp->l = curr->r;  /*   y    z     curr    */
		curr->r = temp;     /*    \         /  \    */
		// update height    /*     T       T    z   */
		temp->h = max(getH(temp->l), getH(temp->r)) + 1;
		curr->h = max(getH(curr->l), getH(curr->r)) + 1;
		return curr;
	}

	Node* clear(Node* curr) {
		if (curr != NULL) {
			curr->l = clear(curr->l);
			curr->r = clear(curr->r);
		}
		return curr = delNode(curr);
	}

	Node* insert(Node* curr, const char _key[], const char _data[]) {
		if (curr == NULL) {
			curr = newNode(_key, _data);
		} else {
			if (strcmp(_key, curr->key) < 0) {
				curr->l = insert(curr->l, _key, _data);
			} else if (strcmp(_key, curr->key) == 0) {
				return curr;
			} else if (strcmp(_key, curr->key) > 0) {
				curr->r = insert(curr->r, _key, _data);
			}
			// Rebalancing
			int BF = getH(curr->r) - getH(curr->l);
			if (BF < -1 && strcmp(_key, curr->l->key) < 0) {
				curr = rotR(curr);
			} else if (BF < -1 && strcmp(_key, curr->l->key) > 0) {
				curr->l = rotL(curr->l);
				curr = rotR(curr);
			} else if (BF > 1 && strcmp(_key, curr->r->key) < 0) {
				curr->r = rotR(curr->r);
				curr = rotL(curr);
			} else if (BF > 1 && strcmp(_key, curr->r->key) > 0) {
				curr = rotL(curr);
			}
			// Balance Case
			curr->h = max(getH(curr->l), getH(curr->r)) + 1;
		}
		return curr;
	}

	Node* remove(Node* curr, const char _key[]) {
		if (curr != NULL) {
			if (strcmp(_key, curr->key) < 0) {
				curr->l = remove(curr->l, _key);

			} else if (strcmp(_key, curr->key) == 0) {
				if (curr->r) {
					Node* temp = getLeftmost(curr->r);
					strcpy(curr->key, temp->key);
					strcpy(curr->data, temp->data);
					curr->r = remove(curr->r, temp->key);
				} else if (curr->l){
					Node* temp = curr;
					curr = curr->l;
					delNode(temp);
					return curr;
				} else {
					return curr = delNode(curr);
				}

			} else if (strcmp(_key, curr->key) > 0) {
				curr->r = remove(curr->r, _key);
			}
			// Rebalancing
			int BF = getH(curr->r) - getH(curr->l);
			if (BF < -1 && strcmp(_key, curr->l->key) < 0) {
				curr = rotR(curr);
			} else if (BF < -1 && strcmp(_key, curr->l->key) > 0) {
				curr->l = rotL(curr->l);
				curr = rotR(curr);
			} else if (BF > 1 && strcmp(_key, curr->r->key) < 0) {
				curr->r = rotR(curr->r);
				curr = rotL(curr);
			} else if (BF > 1 && strcmp(_key, curr->r->key) > 0) {
				curr = rotL(curr);
			}
			// Balance Case
			curr->h = max(getH(curr->l), getH(curr->r)) + 1;
		}
		return curr;
	}

public:
	int reset() {
		root = clear(root);
		return 0;
	}
	int insert(const char key[], const char res[]) {
		root = insert(root, key, res);
		return 0;
	}
	int remove(const char key[]) {
		assert(find(key));
		root = remove(root, key);
	}
	bool find(const char key[]) {
		return search(root, key) != NULL;
	}
	char* operator[](const char key[]) {
		if (search(root, key) == NULL) root = insert(root, key, "");
		return search(root, key)->data;
	}
};
