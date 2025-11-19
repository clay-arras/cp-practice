#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

void solve(){
	int n, k; cin >> n >> k;
	string s; cin >> s;

	if (equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) || k==0){
		cout << 1 << endl;
		return;
	}else{
		cout << 2 << endl;
		return;
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