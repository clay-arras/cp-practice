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

    vector<vector<int>> A(N, vector<int>(M));
    for (auto &i : A) {
        for (auto &j : i)
            cin >> j;
    }
    vector<vector<int>> B(N, vector<int>(M));
    for (auto &i : B) {
        for (auto &j : i)
            cin >> j;
    }

    multiset<multiset<int>> rA, rB;
    for (int i=0; i<N; i++) {
        multiset<int> tsa, tsb;
        for (int j=0; j<M; j++) {
            tsa.insert(A[i][j]);
            tsb.insert(B[i][j]);
        }
        rA.insert(tsa);
        rB.insert(tsb);
    }

    multiset<multiset<int>> cA, cB;
    for (int j=0; j<M; j++) {
        multiset<int> tsa, tsb;
        for (int i=0; i<N; i++) {
            tsa.insert(A[i][j]);
            tsb.insert(B[i][j]);
        }
        cA.insert(tsa);
        cB.insert(tsb);
    }
    cout << (rA == rB && cA == cB ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
