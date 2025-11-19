#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    vector<int> S(3);
    cin >> S[0] >> S[1] >> S[2];
    sort(S.begin(), S.end());

    if (S[2] - S[0] >= 10)
        cout << "check again" << endl;
    else 
        cout << "final " << S[1] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
