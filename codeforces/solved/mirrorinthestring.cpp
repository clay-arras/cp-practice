#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n; cin >> n;
	string s; cin >> s;

	int index=n-1;
	for (int i=0; i<n-1; i++){
		if (s[i] >= s[i+1]){
			continue;
		}else{
			index=i;
			break;
		}
	}
	if(s[0]==s[1]) index=0;

	s = s.substr(0,index+1);
	cout << s;
	reverse(s.begin(), s.end());
	cout << s << "\n";
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
