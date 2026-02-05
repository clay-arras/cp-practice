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
    unordered_set<int> s;
    cout << (1 << N) - 1 << " ";
    s.insert((1 << N) - 1);

    unsigned int bs = (1 << N) - 1;
    for (unsigned int i=1; i<=N; i++) {
        // unsigned int mask = ((((1U << N) - 1U) << i) >> i) & bs;
        unsigned int mask = (1U << (N - i)) - 1U;
        for (unsigned int j=0; j<1<<i; j++) {
            unsigned int val = (mask | (j << (N-i))) & bs;
            if (s.count(val))
                continue;
            cout << val << " ";
            s.insert(val);
        }
    }

    for (int i=0; i<=(1<<N)-1; i++)
        if (!s.count(i))
            cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
