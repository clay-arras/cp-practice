// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);

	int n; cin >> n;
	int days[n];

	for (int &t: days) cin >> t;
	int ans=1, u=0, counter=-1;
	for (int i=n-1; i>0; i--){
		if (counter != -1 && days[i] != -1 && days[i] != counter){
			cout << -1 << endl;
			return 0;
		}
		if (counter == -1) counter = days[i];
		if (days[i] >= 0) {
			counter = days[i];
		}
		if (counter == 0){
			ans++;
		}
		if (counter < 0){
			u++;
		}
		if (counter > -1) counter--;

	}
	cout << ans << " " << ans+u << endl;
}
	