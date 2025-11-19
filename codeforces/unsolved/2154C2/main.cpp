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

    set<int> s;
    for (int i=0; i<N; i++) {
        set<int> cand;

        int noi = A[i];
        for (int j=2; j*j<=noi; j++) {
            if (noi % j == 0) {
                if (s.count(j) || s.count(noi / j)) {
                    cout << 0 << endl;
                    return;
                }
                cand.insert(j);
                cand.insert(noi / j);
            }
        }
        if (s.count(noi)) {
            cout << 0 << endl;
            return;
        }
        if (noi > 1)
            cand.insert(noi);
        s.merge(cand);
    }

    int ans = INT_MAX;
    s.clear();
    for (int i=0; i<N; i++) {
        set<int> cand;

        int noi = A[i]+1;
        for (int j=2; j*j<=noi; j++) {
            if (noi % j == 0) {
                if (s.count(j) || s.count(noi / j)) {
                    cout << 1 << endl;
                    return;
                }
            }
        }
        if (s.count(A[i]+1)) {
            cout << 1 << endl;
            return;
        }

        noi = A[i];
        for (int j=2; j*j<=noi; j++) {
            if (noi % j == 0) {
                cand.insert(j);
                cand.insert(noi / j);
            }
        }
        if (noi > 1)
            cand.insert(noi);
        s.merge(cand);
    }

    s.clear();
    for (int i=N-1; i>=0; i--) {
        set<int> cand;

        int noi = A[i]+1;
        for (int j=2; j*j<=noi; j++) {
            if (noi % j == 0) {
                if (s.count(j) || s.count(noi / j)) {
                    cout << 1 << endl;
                    return;
                }
            }
        }
        if (s.count(A[i]+1)) {
            cout << 1 << endl;
            return;
        }

        noi = A[i];
        for (int j=2; j*j<=noi; j++) {
            if (noi % j == 0) {
                cand.insert(j);
                cand.insert(noi / j);
            }
        }
        if (noi > 1)
            cand.insert(noi);
        s.merge(cand);
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

/*

changes:
do min.
do sorted set, set the minimum value LARGER than this


 */
