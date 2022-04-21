#include <bits/stdc++.h>
using namespace std; 

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	int x, y; cin >> x >> y;
	pair<int, int> inst[n];
	map<pair<int, int>, int> done[n];

	for (auto& t : inst) cin >> t.first >> t.second;
	for (int k=1; k<=n; k++){
		int ans=0;
		int x_sum=0;
		int y_sum=0;
		// for each existing element in the map
		// add the new values

		// new map??????
		for (int i=0; i<n; i++){
			// for (auto it = done.begin(); it != done.end(); it++){

			// }
			// ADD ONCE
			x_sum += inst[i].first;
			y_sum += inst[i].second;

			ans += done[k-1][make_pair(x - x_sum, y - y_sum)];
			// can't update this yet
			done[k-1][make_pair(x - x_sum, y - y_sum)]++;
		}
		cout << ans << "\n";
	}

	// int n; cin >> n;
	// int k; cin >> k;
	// int a[n];
	// // pair<int, set> mem[k];

	// for (int i=1; i<=k; i++){
	// 	for (int j=0; j<n; j++){

	// 	}
	// }
}