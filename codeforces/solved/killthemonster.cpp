// basic brute force solution. had trouble cause forgot to use ll instead of int.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
	ll ch, cd; cin >> ch >> cd;
	ll mh, md; cin >> mh >> md;
	ll k, w, a; cin >> k >> w >> a;

	for (int i=0; i<=k; i++){
		if(ceil(mh*1.0/(cd+(i*w))) <= ceil((ch*1.0+((k-i)*a))/md)){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
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