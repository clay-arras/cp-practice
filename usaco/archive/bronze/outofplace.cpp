// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

	int N; cin >> N;
	int sorted_line[N], line[N];

	for (int i=0; i<N; i++) {
		cin >> sorted_line[i];
		line[i] = sorted_line[i];
	}

	sort(sorted_line, sorted_line+N);

	int ans=0;
	for (int i=0; i<N; i++){
		if (sorted_line[i] != line[i]) ans++;
	}
	cout << --ans << endl;
}
