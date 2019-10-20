vector<int> indi, arr((int)1e6,0);  arr[0] = INF;  int cnt = 0;

for (int i=0; i<n; i++) {
	int lo = 0, hi = cnt, mid;
	while (lo <= hi){
		mid = (lo+hi) >> 1;
		if (arr[mid] <  lst[i]) lo = mid+1;
		if (arr[mid] >= lst[i]) hi = mid-1;
	}
	arr[lo] = lst[i];  indi.pb(lo);  cnt = max(cnt,lo);
}
vector<int> ans;  int idx = n-1;
for(; cnt>o; idx--) if (indi[idx] == cnt) ans.pb(lst[idx]), cnt--;
reverse(ans.begin(), ans.end());
