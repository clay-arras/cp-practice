#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
	// if (a.length() != b.length()) {
	// 	return a.length() >= b.length();
	// }
	return a+b < b+a;
}

void solve(){
	int n; cin >> n;
	vector<string> s(n);
	for (string& t:s) cin >> t;

	/* sort(all(s), cmp); */
	string ans="";
	for (string& t:s) ans += t;
	// for (string& t:s) cout << t << endl;


	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

   	int t=1;
   	while(t--){
   		solve();
   	}
}
