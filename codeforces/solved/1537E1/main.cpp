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
    string s; cin >> s;

    string ans = s;
    s += s;
    for (int i=0; i<N-1; i++) {
        if (s.substr(0, i+1) < s.substr(i+1, i+1)) {
            ans = s.substr(0, i+1);
            break;
        }
    }
    while ((int)ans.size() < K)
        ans += ans;
    cout << ans.substr(0, K) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}

// time: O(N^2 + logK)
