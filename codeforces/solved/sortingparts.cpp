#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n; cin >> n;

	vector<int> a;
	// for (int &t: a) cin >> t;
	int v;
	for (int i=0; i<n; i++) {
		cin >> v;
		a.emplace_back(v);
	}
	vector<int> b;
	b=a;
	sort(a.begin(), a.end());

	for (int i=0; i<n; i++){
		if (a[i] != b[i]){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
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