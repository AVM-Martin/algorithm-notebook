// Returns the distance from p to the line segment ab. The closest point on ab
// is returned through (cpx, cpy). Works correctly for degenerate line segments
// (a == b). REQUIRES: dist(), distToLine()
double distToLineSegment(
	double ax, double ay, double bx, double by,
	double px, double py, double& cpx, double& cpy
){
	if((bx-ax)*(px-ax) + (by-ay)*(py-ay) < EPS){
		cpx = ax;  cpy = ay;  return dist(ax, ay, px, py);
	}
	if((ax-bx)*(px-bx) + (ay-by)*(py-by) < EPS){
		cpx = bx;  cpy = by;  return dist(bx, by, px, py);
	}
	return distToLine(ax,ay,bx,by, px,py, cpx,cpy);
}
