#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MXBIT = 30;
void solve() {
    int N; cin >> N;

    vector<int> A(N);
    pair<int, int> MX = {-1, -1};
    for (int i=0; i<N; i++) {
        cin >> A[i];
        if (A[i] >= MX.first)
            MX = {A[i], i};
    }
    cout << A << endl;

    // Tell me what this function does
    vector<bool> used(N, false);
    int x = MX.first;
    used[MX.second] = true;
    for (int i=MXBIT; i>=0; i--) {
        if (!(x & (1 << i))) {
            for (int j=0; j<N; j++) {
                if (!used[j] and A[j] & (1 << i)) {

                }
            }
        }
    }
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

Break current into all the bits that aren't set
Find the value that covers the most bits
XOR but also remove all of the bits that aren't in the value

*/
