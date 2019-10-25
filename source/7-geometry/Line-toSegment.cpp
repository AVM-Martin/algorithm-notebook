// Returns the distance from p to the line segment ab. The closest point on ab
// is returned through (cpx, cpy). Works correctly for degenerate line segments
// (a == b). REQUIRES: dist(), distToLine()
typedef double D;
D distToLineSegment(D ax, D ay, D bx, D by, D px, D py, D& cpx, D& cpy) {
	if ((bx-ax)*(px-ax) + (by-ay)*(py-ay) < EPS) {
		cpx = ax;  cpy = ay;  return dist(ax, ay, px, py);
	}
	if ((ax-bx)*(px-bx) + (ay-by)*(py-by) < EPS) {
		cpx = bx;  cpy = by;  return dist(bx, by, px, py);
	}
	return distToLine(ax,ay,bx,by, px,py, cpx,cpy);
}
