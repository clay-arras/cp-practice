#include <bits/stdc++.h>
using namespace std; 

void solve(){
	int m, n, k; cin >> m >> n >> k;

	bool ok = true;
	for (int i=0; i<n; i++){
		int a; cin >> a;
		if (abs(a - (i%m + 1)) > k){
			ok=false;
		}
	}
	cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t; cin >> t;
	while(t--){
		solve();
	}
}