#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n, k; cin >> n >> k;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];

	sort(a, a+n);

	int ans=0;
	for (int i=0, r=n-2*k; i<r; i++) ans += a[i];
	for (int i=n-2*k, r=n-k; i<r; i++){
		if (a[i] == a[i+k]) ans++;
	}
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