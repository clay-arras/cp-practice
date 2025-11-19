#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// bool get_(int sel, int i) {
//     return ((sel & (1 << i)) >> i);
// };
// int set_(int sel, int i, bool val) {
//     if (val) return (sel | (1 << i));
//     else     return (sel & (~(1 << i)));
// };
//
// int reverse(int j) {
//     int sel = (bts >> (N-j));
//     int mask = ((bts << j) >> j);
//     for (int i=0; i<ceil(j*1.0/2); i++) {
//         bool tmp = get_(sel, i);
//         sel = set_(sel, i, get_(sel, j-i-1));
//         sel = set_(sel, j-i-1, tmp);
//     }
//     return sel | mask;
// }
//
// int shift(int j) {
//     int sel = (bts >> (N-j)) << (N-j);
//     int mask = ((bts << (j+1)) >> (j+1));
//
//     sel = (sel >> 1);
//     sel = set_(sel, 0, get_(bts, N-j-1));
//
//     return mask | sel;
// }

void solve() {
    string s; cin >> s;
    int N = (int)s.size();

    vector<int> flips(N, 0);
    for (int i=1; i<N; i++) {
        if (s[i] == 'a') {
            flips[i]++;
            flips[i-1]++;
        }
    }

    for (int i : flips)
        cout << (i % 2) << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}

/*
missed: inductive assumption

also didn't realize ints dont fit
also it's NEVER optimal only to flip, it always makes sense to shift
idea: always try constructing the optimal solution, and if it doesn't work then change approaches

*/
