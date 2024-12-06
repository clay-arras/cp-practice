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

    vector<pair<int, int>> ans(N);
    ans[N-1].second = 2*N-1;
    ans[0].first = 2*N;

    for (int i=1; i<N; i++) {
        if (i % 2 == 1) ans[i].first = i+1;
        else ans[i].first = 2*N-i;
    }
    for (int i=1; i<N; i++)
        ans[i-1].second = ans[i].first - 1;

    for (int i=0; i<N; i++)
        cout << ans[i].first << " ";
    cout << endl;
    for (int i=0; i<N; i++)
        cout << ans[i].second << " ";
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
