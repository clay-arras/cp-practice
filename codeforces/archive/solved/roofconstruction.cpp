// main idea was that we had to split the biggest 2^k so the largest 1 in the bit would cancel out. also learned that 1 << y => 2^y

#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
void solve(){
	int n; cin >> n;
	int k = 1 << (int)floor(log2(n-1));

	for(int i=k-1; i>=0; i--) {
    	cout << i << ' ';
    }
    for(int i=k; i<n; i++) {
        cout << i << ' ';
    }    
    cout << endl;
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