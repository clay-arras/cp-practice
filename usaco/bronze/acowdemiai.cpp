// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, L; cin >> N >> L;

	int c[N];
	for (int &t : c) cin >> t;
	sort(c, c+N, greater<int>());

	int h=0, k=0;
	for (int i=0; i<N; i++){
		if (c[i] >= h+1){
			h++;
		} else {
			break;
		}
	}

	for (int i=0; i<h; i++){
		if (c[i] == h) k++;
		else if (c[i] < h) break;
	}
	if (L >= k+1 && c[h] == h) h++;
	
	cout << h << endl;
}
