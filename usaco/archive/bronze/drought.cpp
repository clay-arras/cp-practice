// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n; cin >> n;

	int cows[n]; int sum=0;
	for (int i=0; i<n; i++){
		cin >> cows[n];
		sum += cows[n];
	}

	int minv = cows[0];
	int counter = 0; int v; int k=-1;
	while (counter < n-1){
		counter=0;
		for (int i=0; i<n-1; i++){
			v = cows[i] - minv;
			if (cows[i] < 0 || cows[i+1] < 0){
				cout << -1 << endl;
				return;
			}
			minv = min(minv, cows[i+1]);
			if (cows[i] == cows[i+1]) counter++;
		}
		// if (counter == n-2) {
		// 	cout << -2 << endl;
		// 	return;
		// }
		k = minv;
	}
	cout << k << endl;

}

int main() {
	int T; cin >> T;
	while(T--){
		solve();
	}
}
