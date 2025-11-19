// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	int N; cin >> N;
	int coords[N][2];

	for (int i=0; i<N; i++){
		cin >> coords[i][0] >> coords[i][1];
	}
	int max_A = -1, A;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			for (int k=0; k<N; k++){
				if (coords[i][1] == coords[j][1] && coords[i][0] == coords[k][0]) {
					A = abs((coords[j][0] - coords[i][0])*(coords[k][1] - coords[i][1]));
					max_A = max(max_A, A);
				}
			}
		}
	}
	cout << max_A << endl;
}
