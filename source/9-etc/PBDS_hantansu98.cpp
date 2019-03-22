// Source: hantansu98
// find by order returns an iterator to the k-th smallest element
// (counting from zero) order of key returns the number of items in
// a set that are strictly smaller than our item
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
			tree_order_statistics_node_update> ordered_set;
// inside int main
int n;  scanf("%d", &n);  ordered_set me;
while(n--){
	char t[5];  int x;  scanf("%s %d", t, &x);
	if(t[0] == 'K'){
		if(x > me.size()) puts("invalid");
		else printf("%d\n", *me.find_by_order(x-1));
	}
	if(t[0] == 'C') printf("%d\n", me.order_of_key(x));
	if(t[0] == 'I') me.insert(x);
	if(t[0] == 'D') me.erase(x);
}