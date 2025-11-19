// solution had to do with parity

#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

void solve(){
	ll n, x, y; cin >> n >> x >> y;

	int a, b=y%2; 
	while(n--){
		cin >> a; 
		if (a%2 == b) b = 0;
		else b = 1;
	}
	if (b == x%2) cout << "Alice" << endl;
	else cout << "Bob" << endl;
}

int main() {
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