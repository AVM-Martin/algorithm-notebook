#include <fstream>
// inside main()
ifstream in("plank.in");  ofstream out("plank.out");
priority_queue< long long, vector<long long>, greater<long long> > q;
long long cost = 0;  int N;  in >> N;
for (int i=0; i<N; i++) { long long x;  in >> x;  q.push(x); }
for (; (int)q.size() >= 2; ) {
	long long a = q.top();  q.pop();  long long b = q.top();  q.pop();
	cost += a + b;  q.push(a + b);
}
out << cost << "\n";
