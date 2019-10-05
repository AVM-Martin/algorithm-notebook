class Line{
	public :
	Point p1, p2;
	Line(){}
	Line(Point _p1, Point _p2):p1(_p1),p2(_p2){}
	bool intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double& x, double& y){
		double nom = (x2-x1)*(y1-y3) + (y2-y1)*(x3-x1);
		double den = (x2-x1)*(y4-y3) - (x4-x3)*(y2-y1);
		if(den==0) return false;
		double b = nom/den;
		x = x3 + (x4-x3) * b;  y = y3 + (y4-y3) * b;
		double a = ((x-x1) / (x2-x1));
		if(x2-x1 == 0) a = ((y-y1) / (y2-y1));
		return 0<=a && a<=1 && 0<=b && b<=1;
	}
	bool intersect(Line &that, Point &p){
		return intersect(p1.x, p1.y, p2.x, p2.y, that.p1.x, that.p1.y, that.p2.x, that.p2.y, p.x, p.y);
	}
};
class Polygon {
	public :
	VP P;
	Polygon(){}
	Polygon(VP _P):P(_P){}
	void addPoint(Point p){P.push_back(p);}
	Polygon intersect(Polygon &that) {
		double qarea = that.area(), parea = area();
		VP &Q = that.P;  set<Point> p;  Point pt;
		REP(i,P.size()){
			int ni = (i+1)%P.size();
			Point p1(P[i].x, P[i].y), p2(P[ni].x,P[ni].y);
			Line L1(p1, p2);
			REP(j,Q.size()){
				int nj = (j+1)%Q.size();
				Point p3(Q[j].x, Q[j].y), p4(Q[nj].x,Q[nj].y);
				Line L2(p3, p4);
				if(L1.intersect(L2,pt)) p.insert(pt);
		}	}
		REP(i,P.size()){
			double a = 0;  FOR(j,Q.size())
				a += fabs(det(Q[j],Q[(j+1)%Q.size()], P[i])/2);
			if(fabs(a-qarea) < EPS) p.insert(P[i]);
		}
		REP(i,Q.size()){
			double a = 0;  FOR(j,P.size())
				a += fabs(det(P[j],P[(j+1)%P.size()], Q[i])/2);
			if(fabs(a-parea) < EPS) p.insert(Q[i]);
		}
		return Polygon(cHull(VP(p.begin(),p.end())));
	}
	double area(){
		double ret = 0;
		REP(i, P.size()){
			int ni = (i+1)%P.size();
			ret += P[i].x*P[ni].y - P[i].y*P[ni].x;
		}
		return fabs(ret/2);
}	};
// inside int main
Polygon P, Q;
for(int nA,nB, x,y; scanf("%d",&nA)!=EOF && nA; ){
	FOR(i,nA) scanf("%d %d",&x,&y), P.addPoint(Point(x,y));
	scanf("%d", &nB);
	FOR(i,nB) scanf("%d %d",&x,&y), Q.addPoint(Point(x,y));
	Polygon I = P.intersect(Q);
	printf("%lf\n", P.area() + Q.area() - 2 * I.area());
}
