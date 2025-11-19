#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using str = string;

void solve(){
	string s; cin >> s;
	sort(s.begin(), s.end());
	cout << s << endl;

}

int main() {
	#ifndef ONLINE_JUDGE
   		freopen("input.txt", "r", stdin);
   		freopen("output.txt", "w", stdout);
   	#endif

	int N; cin >> N;
	while(N--){
		solve();
	}

	return 0;
}