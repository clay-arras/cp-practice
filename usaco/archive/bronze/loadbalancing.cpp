// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
vector<int> x, y;
int N, B; 

int count(int a, int b){
	int q1(0), q2(0), q3(0), q4(0), x0, y0;
	for (int i=0; i<N; i++){
		x0 = x[i]; y0 = y[i];
		if (a > x0 && b > y0) q1++;
		else if (a < x0 && b > y0) q2++;
		else if (a > x0 && b < y0) q3++;
		else if (a < x0 && b < y0) q4++;
	}
	return max({q1, q2, q3, q4});
}
int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	cin >> N >> B;
	x.resize(N); y.resize(N);
	for (int i=0; i<N; i++) cin >> x[i] >> y[i];

	int ans = INT_MAX;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			ans = min(ans, count(x[i]+1, y[j]+1));
		}
	}
	cout << ans << endl;
}
