#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define arr array
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void solve(){
	int n; cin >> n;

	int ans=0;
	while(n--){
		int a; cin >> a;
		ans |= a;
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

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}

	return 0;
}