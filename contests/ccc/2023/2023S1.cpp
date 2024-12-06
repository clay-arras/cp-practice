#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// note: count the number of adjacent black triangles
const long long MX = 2e5+5;
int box[MX][2];

void solve() {
    long long N, M; cin >> N; M = 2;

    for (int j=0; j<M; j++)
        for (int i=0; i<N; i++)
            cin >> box[i][j];

    long long adjs = 0, black = 0;
    for (int j=0; j<M; j++) {
        for (int i=0; i<N; i++) {
            if (box[i][j] == 1) {
                if (i+1 < N) adjs += box[i+1][j];
                if (i % 2 == 0) {
                    if (j+1 < M) adjs += box[i][j+1];
                }
                black++;
            }
        }
    }
    cout << 3LL*black - 2LL*adjs << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

