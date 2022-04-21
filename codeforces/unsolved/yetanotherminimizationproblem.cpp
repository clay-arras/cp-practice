#include <bits/stdc++.h>
using namespace std; 

#define ll long long;
#define arr array;

void solve(){
	int n=4;
	int a[n], b[n];


	for (int &t : a) cin >> t;
	for (int &t : b) cin >> t;

	// sort(a, a+8);
	int cost=0;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			cost += (a[i] + a[j])*(a[i] + a[j]);
			cost += (b[i] + b[j])*(b[i] + b[j]);
		}
	}
	cout << cost << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);

   	int t=1;
   	while (t--){
   		solve();
   	}
}
