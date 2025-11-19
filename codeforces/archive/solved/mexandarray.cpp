#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define arr array
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void solve(){
	int n; cin >> n;
	vector<int> a(n+1, 0);
	for (int i=0; i<n; i++){
		int t; cin >> t;
		a[i+1] = a[i];
		if (!t) a[i+1]++; 
	}

	int ans=0;
	for (int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			ans += a[j]-a[i-1] + j-(i-1);
		}
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
   	while (t--){
   		solve();
   	}

	return 0;
}