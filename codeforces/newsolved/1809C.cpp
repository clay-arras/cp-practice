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

    if (K == 0) {
        for (int i=0; i<N; i++)
            cout << -1 << " ";
        cout << endl;
        return;
    }

    int i=1;
    while (i<N and (i+1)*(i+2)/2<=K) i++;
    pair<int, int> val = {i*(i+1)/2, i};
    for (i=0; i<val.second+1 and i<N; i++) {
        if (i == val.second) cout << -100 << " ";
        else if (i == K-val.first-1) cout << 120 << " ";
        else cout << 1 << " ";
    }

    for (; i<N; i++)
        cout << -1000 << " ";
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
 *
 * Case with n=4, k=9

 Find the greatest value of N(N+1)/2 that is smaller than K


*/
