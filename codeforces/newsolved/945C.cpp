#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N; cin >> N;
    vector<int> P(N);
    for (int& i : P)
        cin >> i;

    bool isEven = false;
    vector<pair<int, int>> even, odds;
    for (int i=0; i<N; i++) {
        if (i % 2) {
            odds.push_back({P[i], i});
        } else {
            isEven |= (P[i] == N);
            even.push_back({P[i], i});
        }
    }
    sort(even.begin(), even.end());
    sort(odds.begin(), odds.end());
    vector<int> ans(N);

    if (!isEven) {
        for (int i=0; i<N/2; i++) {
            ans[odds[i].second] = N - i;
            ans[even[i].second] = N/2 - i;
        }
    } else {
        for (int i=0; i<N/2; i++) {
            ans[odds[i].second] = N/2 - i;
            ans[even[i].second] = N - i;
        }
    }
    for (int i=0; i<N; i++)
        cout << ans[i] << " ";
    cout << endl;
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
