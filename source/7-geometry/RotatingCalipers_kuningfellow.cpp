typedef pair<TD,TD> Pt;  const TD EPS = 1e-9;  const TD maxD = 1e9;
// mod = {0: furthest antipodal, 1: min calipers, 2: min bounding rectangle}
// return (antipodal, distance)
vector<Pt> Pts;
template<class TD> vector< pair<int,TD> > rotateCalipers(int mod = 0) {
	int ptr = 0, upd = 0, P1 = 0, P2 = 0;  vector< pair<int,TD> > ret;
	for (int i=0,n=Pts.size(); i<n; i++,upd=ptr) {
		TD d = -1, d1 = -1, d2 = maxD, tmp, l = dist(Pts[i], Pts[(i+1) % n]);
		for (int j=0; j<n; j++) {
			if (d <= fabs(cross(Pts[upd], Pts[(i+1)%n], Pts[i])) / l + EPS) {
				d = fabs(cross(Pts[upd], Pts[(i+1)%n], Pts[i])) / l;
				if (
					mod == 0 && dot(Pts[upd], Pts[(i+1)%n], Pts[i]) >= 0
					&& dot(Pts[upd], Pts[(i-1+n)%n], Pts[i]) >= 0
				) d = dist(Pts[i], Pts[upd]);
				upd = (upd + 1) % n;
			} else break;
		}
		ptr = (upd - 1 + n) % n;
		if (mod == 2) {
			while (d1 <= dot(Pts[P1], Pts[(i+1)%n], Pts[i]) / l + EPS) {
				d1 = dot(Pts[P1], Pts[(i+1)%n], Pts[i]) / l;  P1 = (P1 + 1) % n;
			}
			P1 = (P1 - 1 + n) % n;  if (i == 0) P2 = P1;
			while (d2 >= dot(Pts[P2], Pts[(i+1) % n], Pts[i]) / l - EPS) {
				d2 = dot(Pts[P2], Pts[(i+1) % n], Pts[i])/l;  P2 = (P2 + 1) % n;
			}
			P2 = (P2 - 1 + n) % n;
			d = (d + (d1 - d2)) * 2;  // (d * (d1 - d2)) untuk luas
		}
		ret.push_back(pair<int,TD>(upd, d));
	} return ret;
}
