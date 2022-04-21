// It took me a while to understand the problem. I came up with the algorithm, but the implementation was a bit hard; I used data structures that I didn't need to and which only complicated things.

#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n; cin >> n;
	int p[n], v;
	for (int i=0; i<n; i++){
		cin >> v;
		p[--v] = i;
	}

	string s; cin >> s;
	int count=1, ans[n];
	for (char c='0'; c<='1'; c++){
		for (int i=0; i<n; i++){
			if (s[p[i]] == c){
				ans[p[i]] = count;
				count++;
			}
		}
	}

	for (int t:ans) cout << t << " ";
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
