#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

void solve(){
	int n, k; cin >> n >> k;

	if (n%2 == 1 && k != 1){
		cout << "NO" << endl;
	}else {
		cout << "YES" << endl;
		for (int i=0; i<n; i++){
			for (int j=0; j<k; j++){
				cout << i + n*j + 1 << " ";
			}
			cout << endl;
		}	
	}	
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