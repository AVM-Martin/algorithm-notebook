struct ConvexPolygon {
	Point *p;  int n;
	ConvexPolygon(Point* pp, int nn){ p=pp; n=nn; }
double diameter(){
	int a, b;  double d=(double)0.0, area1, area2;
	if(n == 2) return getDist(p[0], p[1]);
	if(n == 3) return max(getDist(p[0],p[1]), getDist(p[1], p[2]), getDist(p[0], p[2]));
	a = n-1; b = 1;
	area1 = area(p[a], p[(a+1)%n], p[(b+1)%n]);
	area2 = area(p[a], p[(a+1)%n], p[b]);
	while(area1 > area2){
		b = (b+1) % n;
		area1 = area(p[a], p[(a+1)%n], p[(b+1)%n]);
		area2 = area(p[a], p[(a+1)%n], p[b]);
	}
	while(b != 0){
		a = (a+1)%n;
		d = max(d, distance2Point(p[a], p[b]));
		area1 = area(p[a], p[(a+1)%n], p[(b+1)%n]);
		area2 = area(p[a], p[(a+1)%n], p[b]);
		while(area1 > area2){
			b = (b+1)%n;
			area1 = area(p[a], p[(a+1)%n], p[(b+1)%n]);
			area2 = area(p[a], p[(a+1)%n], p[b]);
			if(b == 0) return d;
			d = max(d, distance2Point(p[a], p[b]));
	}	}
	return d;
}	};