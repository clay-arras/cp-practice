// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);

	int cows[3];
	for (int &t : cows) cin >> t;

	sort(cows, cows+3);
	int min_moves=2, max_moves;

	if (cows[0]+1 == cows[1] && cows[1]+1 == cows[2]) min_moves = 0;
	if ((cows[0]+2 == cows[1]) || (cows[1]+2 == cows[2])) min_moves = 1;
	max_moves = max(cows[1]-cows[0], cows[2]-cows[1])-1;

	cout << min_moves << endl << max_moves << endl;
}
