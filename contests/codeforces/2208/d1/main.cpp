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
    vector<vector<bool>> S(N, vector<bool>(N, false));
    for (int i=0; i<N; i++) {
        string s; cin >> s;
        for (int j=0; j<N; j++)
            S[i][j] = (s[j] - '0');
    }

    bool ok1 = true;
    for (int i=0; i<N; i++)
        ok1 &= S[i][i];
    if (!ok1) {
        cout << "NO" << endl;
        return;
    }

    bool ok2 = true;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++)
            ok2 &= (S[i][j] != S[j][i]);
    }
    if (!ok2) {
        cout << "NO" << endl;
        return;
    }



}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
