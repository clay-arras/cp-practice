#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

int N;
vector<int> C, P;

void solve() {
    cin >> N;
    C = vector<int>(N);
    P = vector<int>(N);

    for (int i=0; i<N; i++) {
        int c, p; cin >> c >> p;
        C[i] = c;
        P[i] = p;
    }

    long double ans = 0.0;
    for (int i=N-1; i>=0; i--) 
        ans = max(ans, C[i]*1.0L + ((100 - P[i])*1.0L/100) * ans);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
