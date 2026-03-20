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

    vector<int> p(N);
    for (auto& i : p)
        cin >> i;

    int sum = 0;
    for (int l=0; l<N; l++) {
        for (int r=0; r<N; r++) {

        }
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
