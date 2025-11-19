// Pretty close but not quite. With a bit of math there was a much better implementation of an idea I had. Work out the math more thoroughly next time.

#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<int> a(26, 0);
	for (char c : s) a[c-'a']++;

	int ones=0, twos=0;
	for (int i : a){
		twos += i/2;
		ones += i%2;
	}

	int ans = 2 * (twos/k);
	ones += 2 * (twos%k);
	if (ones >= k) ans++;

	cout << ans << "\n";
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