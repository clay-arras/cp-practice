#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define arr array
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
	void __print(int x) {cerr << x;}
	void __print(long long x) {cerr << x;}
	void __print(float x) {cerr << x;}
	void __print(double x) {cerr << x;}
	void __print(char x) {cerr << '\'' << x << '\'';}
	void __print(const string &x) {cerr << '\"' << x << '\"';}
	void __print(bool x) {cerr << (x ? "true" : "false");}

	template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
	template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}

	void _print() {cerr << "]\n";}
	template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

	#define debug(x...) cerr << "Line " << __LINE__ << ": [" << #x << " = "; _print(x)
	#else
	#define debug(x...)
#endif

void solve(){
	ll n; ll h; cin >> n >> h;
	ll a[n]; for (ll &t:a) cin >> t;

	ll diff[n];
	for (int i=0; i<n-1; i++){
		diff[i] = a[i+1] - a[i];
	}
	diff[n-1]=2e18;
	// CHECK BOUNDS!!!!!!
	sort(diff, diff+n);

	ll sum=0; ll k=-1;
	for (int i=0; i<n; i++){
		if ((h-sum)*1.0/(n-i) <= (float)diff[i]){
			k = ceil((h-sum)*1.0/(n-i));
			break;
		}
		sum += diff[i];
	}
	cout << k << "\n";

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}

	return 0;
}

