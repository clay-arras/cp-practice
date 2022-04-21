// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int N, K; cin >> N >> K;

	int dia[N];
	for (int& t : dia) cin >> t;

	sort(dia, dia+N);
	int ans = 0;
	int count;

	for (int i=0; i<N; i++){
		count = 1;
		for (int j=i+1; j<N; j++){
			if (dia[j]-dia[i]<=K) count++;
			else break;
		}
		ans = max(ans, count);
	}
	cout << ans << endl;
}
