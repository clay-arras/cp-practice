// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
bool pairs[20][20];

int main() {
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int K, N; cin >> K >> N;
	int places[N];

	while(K--){
		for (int &t : places) cin >> t;

		for (int i=0; i<N; i++){
			for (int j=i+1; j<N; j++){
				pairs[places[i]-1][places[j]-1] = true;
			}
		}
	}
	int count = 0;
	for (int i=0; i<N; i++){
		for (int j=i+1; j<N; j++){
			if(!pairs[i][j] || !pairs[j][i]) count++;
		}
	}
	cout << count;
}
