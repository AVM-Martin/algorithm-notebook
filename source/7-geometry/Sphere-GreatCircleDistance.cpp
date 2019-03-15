const double R = 6371.01;
double a=sin(plat)*sin(qlat);
double b=cos(plat)*cos(qlat)*cos(plong)*cos(qlong);
double c=cos(plat)*cos(qlat)*sin(plong)*sin(qlong);
return R * acos(a + b + c);