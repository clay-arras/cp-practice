// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
	int n; cin >> n;
	int a[n]; int b[n];
 
	for (int &t : a) cin >> t;
	for (int &t : b) cin >> t;
 
	int max_a=0, max_b=0;
	int temp;
	for (int i=0; i<n; i++){
		if (a[i] > b[i]){
			temp = a[i];
			a[i] = b[i];
			b[i] = temp;
		}
		max_a = max(max_a, a[i]);
		max_b = max(max_b, b[i]);
	}
	cout << max_a * max_b << endl;
}
 
int main() {
	int t; cin >> t;
	while (t--){
		solve();
	}
}