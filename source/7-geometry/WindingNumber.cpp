bool isInside(Pt pv, vector<Pt> &x) {
	int n = (int)x.size(), wn = 0;  x.push_back(x[0]);
	for (int i=0; i<n; i++) {
		if (
			((x[i+1].first <= pv.first && x[i].first >= pv.first)
				|| (x[i+1].first >= pv.first && x[i].first <= pv.first))
			&& ((x[i+1].second <= pv.second && x[i].second >= pv.second)
				|| (x[i+1].second >= pv.second && x[i].second <= pv.second))
		){
			if (cross(x[i], x[i+1], pv) == 0) { x.pop_back(); return true; }
	}	}
	for (int i=0; i<n; i++) {
		if (x[i].second <= pv.second)
			wn += (x[i+1].second > pv.second && cross(x[i],x[i+1],pv) > 0);
		else wn -= (x[i+1].second <= pv.second && cross(x[i],x[i+1],pv) < 0);
	} x.pop_back();  return wn != 0;
}
