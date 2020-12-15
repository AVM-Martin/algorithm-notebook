#pragma GCC optimize("O3")
const int OO = (int)1e9;
const ll INF = (ll)2e18;

int irand(int lo, int hi) { // random
	return ((double)rand() / (RAND_MAX+1.0)) * (hi - lo + 1) + lo;
}
string toString(ll x) { // ll to string
	stringstream ss;  ss << x;  return ss.str();
}
long long toNumber(string S) { // string to ll
	ll ret;  sscanf(S.c_str(), "%lld", &ret);  return ret;
}
void ioSync() { // iostream sync
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
}
void randomStuff() { // better random: https://codeforces.com/blog/entry/61587
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int random_number = uniform_int_distribution<int>(0, i)(rng); // mt19937_64
	// shuffle(vec.begin(), vec.end(), rng);
	// v.erase(unique(v.begin(), v.end()), v.end());
}
#define getc getchar
template<typename T> T getnum(){
	int sign = 1;  T ret = 0;  char c;
	do { c = getc(); } while (c == ' ' || c == '\n');
	if (c == '-') sign = -1;  else ret = c - '0';
	while (c = getc(), '0' <= c && c <= '9') ret = 10 * ret + c - '0';
	return sign * ret;
}
