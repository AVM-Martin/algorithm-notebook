#include <fstream>
// inside int main
ifstream in("plank.in");  ofstream out("plank.out");
priority_queue< ll,vector<ll>,greater<ll> > q;
int N;  ll cost = 0;  in >> N;
FOR(i,N){ ll x;  in >> x;  q.push(x); }
for(; (int)q.size() >= 2;){
	ll a = q.top();  q.pop();  ll b = q.top();  q.pop();
	cost += a+b;  q.push(a + b);
} out << cost << "\n";
