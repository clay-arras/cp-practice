#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

void solve(){
	string s; cin >> s;

	int len = (int)s.size();

	int ones=0, zeroes=0;
	for (int i=0; i<len; i++){
		if (s[i]-'0'){
			ones++;
		} else zeroes++;
	}

	if (ones == zeroes) cout << min(ones, zeroes)-1 << endl;
	else cout << min(ones, zeroes) << endl;
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