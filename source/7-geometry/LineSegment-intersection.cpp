struct Vertex { int x,y; };
int GetArea2(Vertex& a, Vertex& b, Vertex& c) {
	return (b.x-a.x) * (c.y-a.y) - (c.x-a.x) * (b.y-a.y);
}
bool OnSegment(Vertex& a, Vertex& b, Vertex& c) {
	return (
		min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)
		&& min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y)
	);
}
bool IsInside(Vertex& a, Vertex& lt, Vertex& rb) {
	return (
		min(lt.x, rb.x) <= a.x && a.x <= max(lt.x, rb.x)
		&& min(lt.y, rb.y) <= a.y && a.y <= max(lt.y, rb.y)
	);
}
bool IsIntersect(Vertex& a, Vertex& b, Vertex& c, Vertex& d) {
	int d1 = GetArea2(c, d, a), d2 = GetArea2(c, d, b);
	int d3 = GetArea2(a, b, c), d4 = GetArea2(a, b, d);
	if (
		((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
		&& ((d3 > 0 && d4 < 0) || d3 < 0 && d4 > 0)
	) return true;
	if (d1 == 0 && OnSegment(c, d, a)) return true;
	if (d2 == 0 && OnSegment(c, d, b)) return true;
	if (d3 == 0 && OnSegment(a, b, c)) return true;
	if (d4 == 0 && OnSegment(a, b, d)) return true;
	return false;
}
// line intersection
struct Vertex {
	int x, y; Vertex result;
	Vertex operator-(Vertex& b) {
		result.x = x - b.x;  result.y = y - b.y;  return result;
}	};
void GetIntersectionAttribute(
	Vertex& a, Vertex& b, Vertex& c, Vertex& d, int& fN, int& sN, int& D
){
	fN = (d.x-c.x)*(a.y-c.y) - (d.y-c.y)*(a.x-c.x);
	sN = (b.x-a.x)*(a.y-c.y) - (b.y-a.y)*(a.x-c.x);
	D = (d.y-c.y)*(b.x-a.x) - (d.x-c.x)*(b.y-a.y);
}
double GetIntersectionTime (int N, int D) { return (double)N / (double)D; }
double GetIntersectionX(Vertex& a, Vertex& b, double t){
	return a.x + (b - a).x * t;
}
double GetIntersectionY(Vertex& a, Vertex& b, double t) {
	return a.y + (b - a).y * t;
}
