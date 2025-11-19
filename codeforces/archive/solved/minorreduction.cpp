// stuff with strings, had to test more cases probably. can convert char to int by -'0' (only works with chars). also when the problem is wrong 90% of the time it's the algorithm written wrong not implementation wrong.

#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
void solve(){
	string n; cin >> n;
	int len = (int)n.size();

	int j=0;
	for (int i=len-1; i>0; i--){
		if ((n[i]-'0') + (n[i-1]-'0') >= 10){
			j=i-1;
			break;
		}
	}

	cout << n.substr(0, j) << (n[j]-'0')+(n[j+1]-'0') << n.substr(j+2) << endl;
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
