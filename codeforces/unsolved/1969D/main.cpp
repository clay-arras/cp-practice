#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N), B(N);
    for (int& i : A)
        cin >> i;
    for (int& i : B)
        cin >> i;

    vector<pair<int, int>> T;
    for (int i=0; i<N; i++) {
        if (A[i] < B[i])
            T.push_back({B[i], A[i]});
    }
    sort(T.begin(), T.end());

    int M = (int)T.size();
    vector<int> pref(M+1, 0);
    for (int i=1; i<=M; i++)
        pref[i] = pref[i-1] + T[i-1].first;

    int ans = 0;
    int prof = 0;
    cerr << T << endl;
    for (int i=0; i<M; i++) {
        prof += T[i].first - T[i].second;
        if (i+1+K<=M) {
            int cost = pref[i+1+K] - pref[i+1];
            ans = max(ans, prof - cost);
            cerr << prof - cost << endl;
        }
    }
    cout << max(0, ans) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
