// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n; cin >> n;
	int a[n];

	for (int &t: a) cin >> t;
	
	int counter=1, cons=1;
	for (int i=0; i<n-1; i++){
		if (a[i] == a[i+1]){
			counter++;
		}else{
			cons = max(cons, counter);
			counter=1;
		}
	}
	cons = max(cons, counter);
	cout << ceil(log2((float)n/cons)) << endl;~
}

int main() {
	int t; cin >> t;
	while (t--){
		solve();
	}
}
