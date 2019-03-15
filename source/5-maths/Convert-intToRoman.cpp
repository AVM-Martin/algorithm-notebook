const string R[] = {"M","CM","D","CD","C","XC", \
    "L","XL","X","IX","V","IV","I"};
const int N[] = { 1000, 900, 500, 400, 100, 90, \
    50, 40, 10, 9, 5, 4, 1};

string toRoman(int x){
	if(x == 0)return "O"; // Not decimal 0 !
	int n = sizeof(N)/sizeof(int); // 13
	string res = "";
	FOR(i,n) while(x >= N[i]) x-=N[i], res+=R[i];
	return res;
}