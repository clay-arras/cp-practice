// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);

	int N; cin >> N;
	int rooms[N];
	for (int i=0;i<N;i++){
		cin >> rooms[i];
	}

	int ans(INT_MAX), sum;
	for (int i=0;i<N;i++){
		sum = 0;
		for (int j=0;j<N;j++){
			sum += j*rooms[(i+j)%N];
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
}
