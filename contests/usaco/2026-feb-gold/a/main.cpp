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

    vector<int> C(N);
    for (int i=0; i<N; i++)
        C[i] = A[i] + B[i];

    sort(C.begin(), C.end());
    int T = accumulate(A.begin(), A.end(), -K);
    cerr << C << endl;
    cerr << T << endl;
    cerr << endl;

    int ans = 0;
    for (int i=1; i<N/2 && T>0; i++) {
        int con = i * (C[i] - C[i-1]);
        T -= min(con, T);
        assert(T >= 0);
        if (T) ans = -C[i];
    }
    cout << -(T / N) + *max_element(C.begin(), C.end()) + ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
