// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	int x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int max_x = max(x2, x4) - min(x1, x3);
	int max_y = max(y2, y4) - min(y1, y3);

	int max_side = max(max_x, max_y);
	cout << max_side*max_side << endl;

}
