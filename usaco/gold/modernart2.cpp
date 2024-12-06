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

    vector<int> A(N);
    map<int, pair<int, int>> m;
    for (int i=0; i<N; i++) {
        cin >> A[i];

        if (A[i] == 0) continue;
        if (m.count(A[i]))
            m[A[i]].second = i;
        else
            m[A[i]] = {i, i};
    }

    stack<int> s;
    int ans = 0;
    for (int i=0; i<N; i++) {
        if (m[A[i]].first == i) {
            s.push(A[i]);
            ans = max(ans, (int)s.size());
        }
        if ((int)s.size() > 0 and s.top() != A[i]) {
            cout << -1 << endl;
            return;
        }
        if (m[A[i]].second == i) {
            s.pop();
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

/*

Cases:
1 2 1 2 => -1
1 0 1 => -1
1 1 2 2 => 1
1 2 2 1 => 2

Stack and ST + EN
0 1 4 5 1 3 3

*/
