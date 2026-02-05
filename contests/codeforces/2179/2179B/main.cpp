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
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    int sum = 0;
    for (int i=1; i<N; i++)
        sum += abs(A[i-1] - A[i]);

    int ans = sum;
    for (int i=0; i<N; i++) {
        // int del = 0;
        // if (i-1 >= 0) del += abs(A[i-1] - A[i]);
        // if (i+1 < N) del += abs(A[i+1] - A[i]);
        //
        // int a = 0, b = 0;
        // if (i-1 >= 0) a = A[i-1];
        // if (i+1 < N) b = A[i+1];
        // int add = abs(a - b);
        //
        // ans = min(ans, sum - del + add);

        if (i-1 < 0) {
            ans = min(ans, sum - abs(A[i+1] - A[i]));
        } else if (i+1 >= N) {
            ans = min(ans, sum - abs(A[i-1] - A[i]));
        } else {
            ans = min(ans, sum - abs(A[i-1] - A[i]) - abs(A[i+1] - A[i]) + abs(A[i-1] - A[i+1]));
        }
    }

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
