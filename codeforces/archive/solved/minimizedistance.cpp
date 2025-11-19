// greedy algorithm, had to look at the answer for implementation

#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

void solve(){
	ll n, k; cin >> n >> k;

	ll a[n]; 
	for (ll &t:a) cin >> t;
	sort(a, a+n);
	
	ll ans=0;
	for (ll i=n-1; i>=0 && a[i]>=0; i-=k) ans += a[i];
	for (ll i=0; i<n && a[i]<0; i+=k) ans -= a[i];

	cout << 2*ans - max(abs(a[0]), a[n-1]) << endl;;
}	

int main() {
	#ifndef ONLINE_JUDGE
   		freopen("input.txt", "r", stdin);
   		freopen("output.txt", "w", stdout);
   	#endif

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}

	return 0;
}