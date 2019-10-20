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
void ioSync() { //iostream sync
	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
}
