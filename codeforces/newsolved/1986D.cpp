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
    string s; cin >> s;

    int ans = INT_MAX;
    deque<int> a;
    for (int i=0; i<N; i++)
        a.push_back(stoi(s.substr(i, 1)));

    a.pop_front();
    for (int i=1; i<N; i++) {
        a.pop_front();
        a.push_back(stoi(s.substr(i-1, 2)));
        int val = a[0];
        if (val == 0) ans = min(ans, 0);
        for (int j=1; j<N-1; j++) {
            if (a[j] == 0) {
                val = 0;
                break;
            } else if (a[j] != 1) {
                val = (val == 1 ? a[j] : val + a[j]);
            }
        }
        ans = min(val, ans);
        a.pop_back();
        a.push_back(stoi(s.substr(i-1, 1)));
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
