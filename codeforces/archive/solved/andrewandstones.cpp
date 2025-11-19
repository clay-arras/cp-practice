#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
#define arr array;

void solve(){
	int n; cin >> n;
	int a[n];

	for (int &t:a) cin >> t;
	if (*max_element(a+1, a+n-1) == 1 or (n == 3 and a[1]%2)){
		cout << -1 << "\n";
		return;
	}

	ll ans=0;
	for (int i=1; i<n-1; i++){
		ans += (a[i]+1)/2;
	
	cout << ans << endl;
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
