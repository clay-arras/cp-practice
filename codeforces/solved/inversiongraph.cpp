#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n; cin >> n;
	int a[n];

	for (int &t : a) cin >> t;

	int ans=0;
	int max_num=0;
	for (int i=0; i<n; i++){
		if (max_num == i){
			ans++;
		}
		max_num = max(max_num, a[i]);
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