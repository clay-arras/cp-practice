#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
void solve(){
	string s; cin >> s;
	int len = (int)s.size();
	if (len <= 10) cout << s << endl;
	else{
		cout << s[0] + to_string(len-2) + s[len-1] << endl;
	}
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

}