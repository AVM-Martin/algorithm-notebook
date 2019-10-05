// Source: https://codeforces.com/contest/986/submission/38743952
ll mulmod(ll a, ll b, ll c); // Russian Peasant
ll extgcd(ll a, ll b, ll& x, ll& y){
	if(a == 0){ x = 0, y = 1;  return b; }
	ll p = b/a, g = extgcd(b - p*a, a, y, x);  x -= p*y;
	return g;
}
bool diophantine(ll a, ll b, ll c, ll& x, ll& y, ll& g){
	if(a == 0 && b == 0){
		if(c == 0){ x = y = g = 0;  return true; }
		return false;
	} else if(a == 0){
		if(c%b == 0){ x = 0;  y = c/b;  g = abs(b);  return true; }
		return false;
	} else if(b == 0){
		if(c%a == 0){ x = c/a;  y = 0;  g = abs(a);  return true; }
		return false;
	}
	g = extgcd(a, b, x, y);  if(c%g != 0) { return false; }
	ll dx = c/a;  c -= dx*a;     ll dy = c/b;  c -= dy*b;
	x = dx + mulmod(x, c/g, b);  y = dy + mulmod(y, c/g, a);
	g = abs(g);  return true;
}
