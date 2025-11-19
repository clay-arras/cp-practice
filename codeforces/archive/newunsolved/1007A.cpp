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
    sort(A.begin(), A.end());

    int count = 0;
    multiset<int> m;
    for (int i=0; i<N; i++) {
        auto it = m.upper_bound(-A[i]);
        if (it != m.end()) {
            count++;
            m.erase(it);
        }
        m.insert(-A[i]);
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*

Strictly smallest number

*/
