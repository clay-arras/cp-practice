#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

void solve(){
	int n; cin >> n;

	vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    vector<int> b = a;
    reverse(b.begin()+1,b.end());

	int x = 1, ans=0;
	while (x < n){
		if (b[1] == b[x+1]){
			x++;
			continue;
		}
		x *= 2;
		ans++;
	}
	cout << ans << endl;
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