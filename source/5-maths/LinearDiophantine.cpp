// given a and b for equation ax + by = GCD(a,b)
// find the x and y and returns GCD(a,b)
int extEuclid(int a, int b, int& x, int& y){
	if(b == 0){ x=1;  y=0;  return a; }
	int res = ext_euclid(b,a%b,x,y);
	int x1 = y, y1 = x-(a/b)*y;  x=x1;  y=y1;
	return res;
}
// Is ax + by = c has integral solution?
bool linearDiop(int a,int b,int c, int& x,int& y){
	int d = extEuclid(a,b,x,y);
	if(c%d != 0)return false;
	x *= c/d;  y *= c/d;  return true;
}