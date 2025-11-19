#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define arr array
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
	void __print(int x) {cerr << x;}
	void __print(float x) {cerr << x;}
	void __print(double x) {cerr << x;}
	void __print(long long x) {cerr << x;}
	void __print(char x) {cerr << '\'' << x << '\'';}
	void __print(bool x) {cerr << (x ? "true" : "false");}
	void __print(const string &x) {cerr << '\"' << x << '\"';}

	template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
	template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}

	void _print() {cerr << "]\n";}
	template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

	#define _cerr() cerr << "\n";
	#define debug(x...) cerr << "L(" << __LINE__ << "): [" << #x << " = "; _print(x);
	#else
	#define debug(x...)
#endif

void solve(){
	int n; cin >> n;
   	map<ll, int> prev;
   	prev[0]=1;

   	ll ans=0, pref=0, a;
   	for (int i=1; i<n+1; i++){
   		cin >> a; pref += a;

   		ans += prev[(pref%n + n)%n];
   		prev[(pref%n + n)%n]++;
   	}
   	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
   		freopen("../io/input.txt", "r", stdin);
   		freopen("../io/output.txt", "w", stdout);
   	#endif

   	int t=1;
   	while(t--){
   		solve();
   	}
	return 0;
}