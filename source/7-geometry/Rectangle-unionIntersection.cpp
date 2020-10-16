struct event { int ind, type;};
struct point { double x,y; };

event events_v[350],events_h[350];  point rect[150][3];
bool in_set[350];  int n;

bool compare_x(event a, event b) {
	return rect[a.ind][a.type].x < rect[b.ind][b.type].x;
}
bool compare_y(event a, event b) {
	return rect[a.ind][a.type].y < rect[b.ind][b.type].y;
}

double union_area(int e) {
	memset(in_set,false,sizeof(in_set));
	sort(events_v,events_v + e, compare_x);
	sort(events_h,events_h + e, compare_y);
	double area = 0;  in_set[events_v[0].ind] = 1;
	for (int i=1; i<=e-1; i++) {
		event c = events_v[i];  int cnt = 0;  double begin_y;
		double delta_x = rect[c.ind][c.type].x
			- rect[events_v[i-1].ind][events_v[i-1].type].x;
		if (delta_x == 0) { in_set[c.ind] = (c.type == 0);  continue; }
		for (int j=0; j<e; j++) {
			if (in_set[events_h[j].ind] == 1) {
				if (events_h[j].type == 0) {
					if (cnt == 0) begin_y = rect[events_h[j].ind][0].y;
					++cnt;
				} else if (--cnt == 0) {
					double delta_y = rect[events_h[j].ind][1].y - begin_y;
					area += delta_x * delta_y;
		}	}	}
		in_set[c.ind] = (c.type == 0);
	}
	return area;
}
int inside_main() {
	while (cin>>n && n!=0) {
		for (int a=0; a<n; a++) {
			double x,y,r;  cin>>x>>y>>r;
			rect[a][0].x = x-r;  rect[a][1].x = x+r;
			rect[a][0].y = y-r;  rect[a][1].y = y+r;
			events_v[2*a].ind = a;   events_v[2*a + 1].ind = a;
			events_v[2*a].type = 0;  events_v[2*a + 1].type = 1;
			events_h[2*a].ind = a;   events_h[2*a + 1].ind = a;
			events_h[2*a].type = 0;  events_h[2*a + 1].type = 1;
		}
		printf("%.2lf\n", union_area(2*n));
}	}
