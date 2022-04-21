// I found a algorithm that worked, but it was lengthy to code (although it used less memory than this one). However, this one is better as it is simpler to code

#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n, m; cin >> n >> m;
	vector<int> a;
	
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			a.emplace_back(max(i, n-i-1) + max(j, m-j-1));
		}
	}
	sort(a.begin(), a.end());
	for (int i=0, len=m*n; i<len; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
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