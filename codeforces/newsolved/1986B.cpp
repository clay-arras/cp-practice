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
    vector<vector<int>> A(N, vector<int>(M, 0));
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> A[i][j];

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int val = 0;
            bool ok = true;
            if (i - 1 >= 0) {
                val = max(val, A[i-1][j]);
                ok &= (A[i][j] > A[i-1][j]);
            }
            if (j - 1 >= 0) {
                val = max(val, A[i][j-1]);
                ok &= (A[i][j] > A[i][j-1]);
            }
            if (i + 1 < N) {
                val = max(val, A[i+1][j]);
                ok &= (A[i][j] > A[i+1][j]);
            }
            if (j + 1 < M) {
                val = max(val, A[i][j+1]);
                ok &= (A[i][j] > A[i][j+1]);
            }
            cout << (ok ? val : A[i][j]) << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
