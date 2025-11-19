// Basically keep track of the numbers are done, then keep dividing until you get to another one which wasn't done.

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> a(n), used(n+1, 0);

	for (int &t:a) cin >> t;
	sort(a.rbegin(), a.rend());

	bool b=true;
	for (int i=0; i<n; i++){
		int x=a[i];

		while (x>n or used[x]) x /= 2;
		if (x>0) used[x] = 1;
		else b=false;
	}
	cout << (b ? "YES" : "NO") << "\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
