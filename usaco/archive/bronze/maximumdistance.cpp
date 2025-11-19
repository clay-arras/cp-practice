// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;

 
int main() {
	int N; cin >> N;
	int x[N], y[N];
	int ans(0);
 
	for (int& t: x) cin >> t;
	for (int& t: y) cin >> t;
 
	for (int i=0;i<N;i++){
		for (int j=i+1;j<N;j++){
			ans = max(ans, (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		}
	}
	cout << ans << endl;
}