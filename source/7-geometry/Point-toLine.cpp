// Returns the distance from p to the line defined by {a, b}.The closest point
// on the line is returned through (cpx,cpy). Does not work for degenerate lines
// (when answer isundefined).             cp = a + (p-a).(b-a) / |b-a| * (b-a)
typedef double D;
D distToLine(D ax, D ay, D bx, D by, D px, D py, D& cpx, D& cpy) {
	D a = ((px-ax)*(bx-ax) + (py-ay)*(by-ay));
	D b = ((bx-ax)*(bx-ax) + (by-ay)*(by-ay));
	D proj = a/b;  cpx = ax + proj*(bx - ax);  cpy = ay + proj*(by - ay);
	return dist(px,py, cpx,cpy);
}
