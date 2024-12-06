#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> points(n + 2);
	unordered_map<int, vector<int>> lines[2];
	for (int i=0; i<n + 2; i++) {
		cin >> points[i].first >> points[i].second;
		lines[0][points[i].first].push_back(i);
		lines[1][points[i].second].push_back(i);
	}
	queue<pair<int, bool>> q;
	q.push({0, 1});
	q.push({0, 0});

	vector<int> d(n + 2, 1e9);
	d[0] = 0;
	while (!q.empty()) {
		int curr = q.front().first;
		bool dir = q.front().second;
		q.pop();
		int coord = (dir ? points[curr].first : points[curr].second);
		for (int point : lines[!dir][coord]) {
			if (d[point] == 1e9) {
				q.push({point, !dir});
				d[point] = d[curr] + 1;
			}
		}
	}
	cout << (d[1] == 1e9 ? -1 : d[1] - 1) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

/*



*/
