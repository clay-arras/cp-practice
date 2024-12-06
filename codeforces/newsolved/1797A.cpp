#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, M; cin >> N >> M;

    pair<int, int> c1, c2;
    cin >> c1.first >> c1.second >> c2.first >> c2.second;

    int ans = 4;
    int sum = 0;
    if (c1.first + 1 <= N) sum++;
    if (c1.second + 1 <= M) sum++;
    if (c1.first - 1 > 0) sum++;
    if (c1.second - 1 > 0) sum++;
    ans = min(sum, ans);

    sum = 0;
    if (c2.first + 1 <= N) sum++;
    if (c2.second + 1 <= M) sum++;
    if (c2.first - 1 > 0) sum++;
    if (c2.second - 1 > 0) sum++;
    ans = min(sum, ans);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*



*/
