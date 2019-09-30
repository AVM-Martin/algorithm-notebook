bool c_intersection(circle C1,circle C2,point &P1,point &P2) {
	double d=e_dist(C1.P,C2.P);
	if (d+EPS>C1.r+C2.r) return false;
	if (d<dabs(C1.r-C2.r)+EPS) return false;
	double x1=C1.P.x, y1=C1.P.y, r1=C1.r, x2=C2.P.x, y2=C2.P.y, r2=C2.r;
	double a=(r1*r1-r2*r2+d*d)/(2*d), h=sqrt(r1*r1-a*a);
	point T(x1+a*(x2-x1)/d,y1+a*(y2-y1)/d);
	P1=point(T.x-h*(y2-y1)/d,T.y+h*(x2-x1)/d);
	P2=point(T.x+h*(y2-y1)/d,T.y-h*(x2-x1)/d);
	return true;
}
bool lc_intersection(line L,circle O,point &P1,point &P2) {
	double a=L.a, b=L.b, c=L.c, x=O.P.x, y=O.P.y, r=O.r;
	double A=a*a+b*b, B=2*a*b*y-2*a*c-2*b*b*x;
	double C=b*b*x*x+b*b*y*y-2*b*c*y+c*c-b*b*r*r;
	double D=B*B-4*A*C; point T1,T2;
	if (same_d(b,0.0)) {
		T1.x=c/a; if (dabs(x-T1.x)+EPS>r) return false;
		if (same_d(T1.x-r-x,0.0) || same_d(T1.x+r-x,0.0)) {
			P1=P2=point(T1.x,y); return true;
		}
		double dx=dabs(T1.x-x), dy=sqrt(r*r-dx*dx);
		P1=point(T1.x,y-dy); P2=point(T1.x,y+dy); return true;
	}
	if (same_d(D,0.0)) {
		T1.x=-B/(2*A); T1.y=(c-a*T1.x)/b; P1=P2=T1; return true;
	}
	if (D<EPS) return false; D=sqrt(D);
	T1.x=(-B-D)/(2*A); T1.y=(c-a*T1.x)/b; P1=T1;
	T2.x=(-B+D)/(2*A); T2.y=(c-a*T2.x)/b; P2=T2;
	return true;
}
bool sc_intersection(segment S,circle C,point &P1,point &P2) {
	bool cek=lc_intersection(S.L,C,P1,P2);
	if (!cek) return false;
	double x1=S.P.x, y1=S.P.y, x2=S.Q.x, y2=S.Q.y;
	bool b1=between_d(P1.x,x1,x2)&&between_d(P1.y,y1,y2);
	bool b2=between_d(P2.x,x1,x2)&&between_d(P2.y,y1,y2);
	if (P1==P2) return b1;
	if (b1||b2) {
		if (!b1) P1=P2; if (!b2) P2=P1; return true;
	}
	return false;
}
circle t_inCircle(point A,point B,point C) {
	vector<point> T; T.clear(); T.pb(A); T.pb(B); T.pb(C);
	sort(T.begin(),T.end());  A=T[0]; B=T[1]; C=T[2];
	double r=t_area(A,B,C)/(t_perimeter(A,B,C)/2);
	double ratio=e_dist(A,B)/e_dist(A,C);
	vec BC(B,C); BC=scale(BC,ratio/(1+ratio));
	point P; P=translate(B,BC); line AP1(A,P);
	ratio=e_dist(B,A)/e_dist(B,C);
	vec AC(A,C); AC=scale(AC,ratio/(1+ratio)); P=translate(A,AC); line BP2(B,P);
	intersection(AP1,BP2,P); return circle(P,r);
}
circle minCoverCircle(polygon &A) {
	vector<point> p = A.P; point c; circle ret;
	double cr = 0.0; int i,j,k; c = p[0];
	for(i = 1; i < p.size(); i++) {
		if(e_dist(p[i], c) >= cr+EPS) {
			c = p[i], cr = 0; ret=circle(c,cr);
			for(j = 0; j < i; j++) {
				if(e_dist(p[j], c) >= cr+EPS) {
					c=mid(p[i],p[j]);
					cr = e_dist(p[i], c); ret=circle(c,cr);
					for(k = 0; k < j; k++) {
						if(e_dist(p[k], c) >= cr+EPS) {
							ret=circle(p[i],p[j],p[k]);
							c=ret.P; cr=ret.r;
	}	}	}	}	}	}
	return ret;
}
