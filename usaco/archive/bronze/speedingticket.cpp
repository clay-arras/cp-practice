// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
	
	int n, m; cin >> n >> m;
	int r_len[n], r_lim[n], b_len[m], b_lim[m];

	for (int i=0; i<n; i++){
		cin >> r_len[i] >> r_lim[i];
		if (i) r_len[i] += r_len[i-1];
	}
	for (int i=0; i<m; i++){
		cin >> b_len[i] >> b_lim[i];
		if (i) b_len[i] += b_len[i-1];
	}

	int r_count(0), b_count(0), ans(0);
	for (int i=1; i<=100; i++){
		if (i > r_len[r_count]) r_count++;
		if (i > b_len[b_count]) b_count++;

		ans = max(ans, b_lim[b_count]-r_lim[r_count]);
	}
	cout << ans << endl;
}
