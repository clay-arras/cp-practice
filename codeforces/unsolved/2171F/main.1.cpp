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
    vector<int> P(N);
    for (int& i : P)
        cin >> i;

    deque<int> dq;
    vector<pair<int, int>> e;
    for (int i=0; i<N; i++) {
        if (!dq.empty() && P[i] > dq.front()) {
            while (!dq.empty()) {
                e.push_back({dq.front(), P[i]});
                dq.pop_front();
            }
        }

        if (dq.empty() || dq.front() < P[i])
            dq.push_front(P[i]);
        else dq.push_back(P[i]);
    }

//         cerr << P << endl;
//         for (auto [f, s] : e)
//             cerr << f << " " << s << endl;
//         cerr << dq << endl;
//         cerr << endl;

    if ((int)dq.size() == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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
