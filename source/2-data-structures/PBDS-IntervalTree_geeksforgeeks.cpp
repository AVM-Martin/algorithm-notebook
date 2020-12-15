// Source: https://www.geeksforgeeks.org/interval-tree-using-gnu-tree-based-container/
typedef pair<int, int> Interval;  const Interval NO_INTERVAL_FOUND = { 1, 0 };

template <class Node_CItr, class Node_Itr, class Cmp_Fn, class _Alloc>
struct interval_node_update_policy {
	typedef int metadata_type;
	//
	void operator()(Node_Itr it, Node_CItr end_it) {
		int mx = (*it)->second;  Node_Itr nxt;
		if ((nxt = it.get_l_child()) != end_it) mx = max(mx, nxt.get_metadata());
		if ((nxt = it.get_r_child()) != end_it) mx = max(mx, nxt.get_metadata());
		const_cast<int&>(it.get_metadata()) = maxx;
	}
	bool doOverlap(Interval i1, Node_CItr i2) {  // additional functions
		return (i1.first <= (*i2)->second && (*i2)->first <= i1.second);
	}
	Interval overlapSearch(Interval i) {
		for (Node_CItr it = node_begin(); it != node_end(); ) {
			if (doOverlap(i, it)) {
				return { (*it)->first, (*it)->second };
			} else if (it.get_l_child() != node_end()) {
				Node_CItr left = it.get_l_child(), right = it.get_r_child();
				it = (left.get_metadata() >= i.first ? left : right);
			} else {
				it = it.get_r_child();
		}	}
		return NO_INTERVAL_FOUND;
	}
	virtual Node_CItr node_begin() const = 0;
	virtual Node_CItr node_end() const = 0;
	virtual ~interval_node_update_policy() {}
};

using IntervalTree = tree<Interval, null_type, less<Interval>, rb_tree_tag,
			interval_node_update_policy>;

void example() {
	IntervalTree ds; Interval intvs[] = { { 15, 20 }, { 10, 30 }, { 17, 19 }};
	for (Interval intv : intvs) ds.insert(intv);
	Interval toSearch = { 25, 29 };  Interval res = ds.overlapSearch(toSearch);
	Interval toErase = { 10, 30 };   ds.erase(toErase);
}
