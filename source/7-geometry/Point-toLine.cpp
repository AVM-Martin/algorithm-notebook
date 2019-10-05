// Returns the distance from p to the line defined
// by {a, b}.The closest point on the line is
// returned through (cpx,cpy). Does not work for
// degenerate lines (when answer isundefined).
// REQUIRES: dist()
// Formula: cp = a + (p-a).(b-a) / |b-a| * (b-a)
double distToLine(double ax, double ay, double bx, double by, double px, double py, double& cpx, double& cpy){
	double a = ((px-ax)*(bx-ax) + (py-ay)*(by-ay));
	double b = ((bx-ax)*(bx-ax) + (by-ay)*(by-ay));
	double proj = a/b;
	cpx = ax + proj*(bx - ax);  cpy = ay + proj*(by - ay);
	return dist(px,py, cpx,cpy);
}
