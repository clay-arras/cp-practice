// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);

	int N; cin >> N;
	int seq[N];

	for (int &t : seq) cin >> t;
	int ans=0;

	for (int i=0; i<N-1; i++){
		if (seq[i] > seq[i+1]){
			ans = i+1;
		}
	}

	// if (seq[N-1] == 1) ans--;
	cout << ans << endl;
}
