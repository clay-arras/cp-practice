#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long mxV = 1e18+8;
void solve() {
    int N; cin >> N;

    vector<long long> h(N);
    for (long long& t : h)
        cin >> t;

    // Two cases: if odd or even length
    // Note: 1 indexed
    vector<long long> ans(N+1, mxV);
    for (int i=0; i<N; i++) {
        long long eSum = 0, oSum = 0;

        for (int j=0; j<N; j++) {
            if (i+j < N and i-j >= 0) {
                oSum += abs(h[i+j] - h[i-j]);
                ans[2*j+1] = min(ans[2*j+1], oSum);
            }
            if (i+j-1 < N and i-j >= 0 and j) {
                eSum += abs(h[i+j-1] - h[i-j]);
                ans[2*j] = min(ans[2*j], eSum);
            }
        }
    }
    for (int i=1; i<=N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

