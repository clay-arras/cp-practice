// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	int a, b, c, d; cin >> a >> b >> c >> d;

	bool overlap = false;
	if (a < d && c < b) overlap = true;

	if (overlap) cout << max(b, d)-min(a, c) << endl;
	}else cout << (b-a) + (d-c) << endl;
}
