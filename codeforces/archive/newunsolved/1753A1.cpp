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

    if (N % 2) {
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> ans;
    for (int i=0; i<N; i+=2) {
        int opt = A[i] + A[i+1];
        switch (opt) {
            case 0:
                ans.push_back({i+1, i+1});
                ans.push_back({i+1+1, i+1+1});
                break;
            case -2:
            case 2:
                ans.push_back({i+1, i+1+1});
                break;
        }
    }
    cout << (int)ans.size() << endl;
    for (auto [f, s] : ans)
        cout << f << " " << s << endl;
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
