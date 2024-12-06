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
    for (int& t : A)
        cin >> t;

    for (int i=1; i<N; i++) {
        if (A[i] % A[i-1] == 0)
            A[i-1]++;
    }
    for (int i=1; i<N; i++) {
        if (A[i] % A[i-1] == 0)
            A[i]++;
    }
    /* bool ok = true; */
    /* for (int i=1; i<N; i++) { */
    /*     ok &= (A[i] % A[i-1] != 0); */
    /* } */
    /* cout << ok << endl; */
    for (int i : A)
        cout << i << " ";
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
