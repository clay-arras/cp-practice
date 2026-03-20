#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    set<int> s;
    for (int i=0; i<N; i++)
        if (A[i] == 1)
            s.insert(i);
    int sum = accumulate(A.begin(), A.end(), 0);
    vector<int> parr(2);

    auto upd = [&]() {
        int cov = (sum % 2);
        parr[cov] = sum;

        int ncov = (cov == 1 ? 0 : 1);
        if (s.empty()) parr[ncov] = -1;
        else {
            int r = min(2 * (*s.begin()), 2* (N-1-*s.rbegin()));
            parr[ncov] = sum - r - 1;
        }
    };


    upd();
    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            int s; cin >> s;
            cout << (parr[s % 2] >= s ? "YES" : "NO") << endl;

        } else {
            int i, v; cin >> i >> v;
            --i;
            sum += v - A[i];
            if (A[i] == 1)
                s.erase(i);
            if (v == 1)
                s.insert(i);
            A[i] = v;
            upd();
        }
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
