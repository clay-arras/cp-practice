// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
vector<string> spotty(100), plain(100);

int solve(int N, int index){
	int a, b;

	int spotty_l[4] = {0};
	int plain_l[4] = {0};

	for (int i=0; i<N; i++){
		a = spotty[i][index];
		if (a == 'A') spotty_l[0] = 1;
		else if (a == 'C') spotty_l[1] = 1;
		else if (a == 'T') spotty_l[2] = 1;
		else if (a == 'G') spotty_l[3] = 1;

		b = plain[i][index];
		if (b == 'A') plain_l[0] = 1;
		else if (b == 'C') plain_l[1] = 1;
		else if (b == 'T') plain_l[2] = 1;
		else if (b == 'G') plain_l[3] = 1;
	}
	int count = 0;
	for (int i=0; i<4; i++){
		if (spotty_l[i] == 1 && plain_l[i] == 1) count++;
	}
	if (count == 0) return 1;
	return 0;
}

int main() {
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int N, M; cin >> N >> M;
	int count = 0;
	spotty.resize(N);
	plain.resize(N);

	for (string &i:spotty) cin >> i;
	for (string &i:plain) cin >> i;

	for (int i=0; i<M; i++){
		count += solve(N, i);
	}
	cout << count << endl;
}

