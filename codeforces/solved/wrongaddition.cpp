// i had the basic algorithm right but the implementation was too hard. next time use vectors mayble

#include <bits/stdc++.h>
#define len(s) (int)s.size()

using namespace std; 
using ll = long long;

void solve(){
	ll a, s; cin >> a >> s;

	vector<int> b;
	while(s){
		int x = a%10;
		int y = s%10;

		if (x <= y) b.emplace_back(y-x);
		else{
			s /= 10;
			y += 10*(s%10);
			if (x < y && y >= 10 && y <= 18) b.emplace_back(y-x);
			else {
				cout << -1 << endl;
				return;
			}
		}
		s /= 10;
		a /= 10;
	}
	if (a){
		cout << -1 << endl;
		return;
	} else{
		while(b.back() == 0) b.pop_back();
		for (int i=len(b)-1; i >=0; i--) cout << b[i];
		cout << endl;
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