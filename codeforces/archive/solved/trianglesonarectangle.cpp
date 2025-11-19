// solved, algorithm is to find the max distance for each side, then find max of those 4 and multiply by the corresponding height. had problems implementing it

#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

void solve(){
	ll w, h; cin >> w >> h;

	ll a[200000], ans=0;
	for (int i=0; i<4; i++){
		int k; cin >> k;
		for(int j=0; j<k; j++) cin >> a[j];
		ans = max(ans, (i<2) ? (a[k-1]-a[0])*h : (a[k-1]-a[0])*w);
	}
	cout << ans << endl;
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
