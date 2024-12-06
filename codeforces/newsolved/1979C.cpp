#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MXN = 1e9;
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    long long tot = 0;
    for (int i=0; i<N; i++)
        tot += MXN*1LL/A[i] + 1;

    bool ans = true;
    for (int i=0; i<N; i++)
        ans &= (tot < (MXN*1LL/A[i]+1)*A[i]);

    if (!ans) {
        cout << -1 << endl;
        return;
    }
    for (int i=0; i<N; i++)
        cout << MXN/A[i] + 1 << " ";
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
