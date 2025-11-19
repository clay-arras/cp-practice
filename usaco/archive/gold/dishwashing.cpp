#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 1e5+5;
int dp[MX];

vector<int> find_lis(vector<int> a) {
	vector<int> dp;
	for (int i : a) {
		int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
		if (pos == (int)dp.size()) {
			dp.push_back(i);
		} else {
			dp[pos] = i;
		}
	}
    return dp;
}

void solve() {
    int N; cin >> N;

    vector<int> A(N);
    for (int& t : A)
        cin >> t;

    for (int i=0; i<N; i++) {

    }
    auto a = find_lis({2, 7, 6, 8, 1, 5, 4, 3});
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*

Observation 1: The order of Elsie's movements is deterministic; for each arrangement of soapy disks, there is only one way to wash them
Discard pile
Keep a piles vector, maximum N piles
Inversions
Is there something smaller that's included

First calculate maximum chains of N, then we can calculate which leaders to use
Either O(N) DP or O(NlogN) Segment Tree

Only keep track of the tops
DP[i] = v
V is the greatest prefix we can obtain from using the first i values

*/
