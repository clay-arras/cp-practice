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
    vector<int> A(N), B(N);
    for (int& i : A)
        cin >> i;
    for (int& i : B)
        cin >> i;
    
    vector<pair<int, int>> ord;
    for (int i=0; i<N; i++)
        ord.push_back({A[i], i});
    sort(ord.begin(), ord.end());

    for (int idx=0; idx<N; idx++) { 
        int i = ord[idx].second;
        for (int j=0; i-j>=0; j++) {
            if (A[i] < A[i-j]) break;
            if (B[i-j] == A[i-j] && A[i-j] != A[i]) break;
            A[i-j] = A[i];
        }
        for (int j=0; i+j<N; j++) {
            if (A[i] < A[i+j]) break;
            if (B[i+j] == A[i+j] && A[i+j] != A[i]) break;
            A[i+j] = A[i];
        }
    }

    bool ok = true;
    for (int i=0; i<N; i++)
        ok &= (A[i] == B[i]);
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
