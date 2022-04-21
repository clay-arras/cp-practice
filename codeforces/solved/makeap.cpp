#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using str = string;

void solve(){
	int a, b, c; cin >> a >> b >> c;
	if ((a+c)%(2*b) == 0 && a+c > 0) cout << "YES" << endl;
	else if ((2*b - c)%a == 0 && 2*b - c > 0) cout << "YES" << endl;
	else if ((2*b - a)%c == 0 && 2*b - a > 0) cout << "YES" << endl;
	else cout << "NO" << endl;
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