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
    if (N <= 3) {
        cout << -1 << endl;
        return;
    }

    if (N % 3 == 1) {
        for (int i=2; i<=N; i+=3)
            cout << i << " ";
        for (int i=N; i>=1; i-=3)
            cout << i << " ";
        for (int i=3; i<=N; i+=3)
            cout << i << " ";
        cout << endl;
    } else if (N % 3 == 2) {
        for (int i=2; i<=N; i+=3)
            cout << i << " ";
        for (int i=N-2; i>=1; i-=3)
            cout << i << " ";
        for (int i=1; i<=N; i+=3)
            cout << i << " ";
        cout << endl;
    } else {
        N--;
        for (int i=2; i<=N; i+=3)
            cout << i << " ";
        for (int i=N-2; i>=1; i-=3)
            cout << i << " ";
        for (int i=1; i<=N; i+=3)
            cout << i << " ";
        cout << N+1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
