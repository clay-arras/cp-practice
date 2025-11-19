#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s; cin >> s;

	if ((int)s.find("R") > (int)s.find("r") and
		(int)s.find("B") > (int)s.find("b") and
		(int)s.find("G") > (int)s.find("g")) {
		cout << "YES\n";
	}else {
		cout << "NO\n";
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

   	int t; cin >> t;
   	while(t--){
   		solve();
   	}
}
