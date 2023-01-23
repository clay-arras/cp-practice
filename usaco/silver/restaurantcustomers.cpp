#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define arr array
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

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
	int n; cin >> n;

	vector<pair<int, int>> cust;
	for (int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		cust.emplace_back(mp(a, b));
	}

	sort(all(cust));
	for (int i=0; i<n; i++) cust[i].first = i+1;
	sort(all(cust), [](pair<int, int> a, pair<int, int> b){return a.second < b.second;});
	for (int i=0; i<n; i++) cust[i].second = i+1;

	debug(cust);

	vector<int> diff(n, 0);
	for (int i=0; i<n; i++){
		diff[cust[i].first-1]--;
		diff[cust[i].second]++;
	}
	int ans=0;
	vector<int> a(n);
	for (int i=1; i<n; i++){
		a[i] = a[i-1] - diff[i];
		ans = max(ans, a[i]);
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