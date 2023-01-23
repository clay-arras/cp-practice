#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

#ifndef ONLINE_JUDGE
	void __print(int x) {cerr << x;}
	void __print(long long x) {cerr << x;}
	void __print(float x) {cerr << x;}
	void __print(double x) {cerr << x;}
	void __print(bool x) {cerr << (x ? "true" : "false");}
	void __print(char x) {cerr << '"' << x << '"';}
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
	int n, x; cin >> n >> x;
	int a[n]; for (int& t:a) cin >> t;

	int l=0, r=0, sum=0;
	int ans=0;
	
	for (;r < n; r++){
		sum += a[r];
		while (sum > x){
			sum -= a[l++];
		}
		if (sum == x) ans++;
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