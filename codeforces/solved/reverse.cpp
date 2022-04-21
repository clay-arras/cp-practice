#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n; cin >> n;
	int a[n];
	for (int &t : a) cin >> t;

	int r=-1, l=-1;
	for (int i=0; i<n; i++){
		if (a[i] == i+1) {
			continue;
		}
		if (l==-1) l = i;
		for (int j=i; j<n; j++){
			if (a[j] == i+1){
				if (r == -1) r = j;
				break;
			}
		}
	}
	if (l == -1){
		for (int &t : a) cout << t << " ";
		cout << "\n";
	}else{
		for (int i=0; i<l; i++) cout << a[i] << " ";
		for (int i=r; i>=l; i--) cout << a[i] << " ";
		for (int i=r+1; i<n; i++) cout << a[i] << " ";
		cout << "\n";
	}
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