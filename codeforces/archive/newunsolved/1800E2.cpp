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
    string s, t; cin >> s >> t;

    vector<int> cnt(26, 0);
    bool ok = true;
    for (int i=0; i<N; i++) {
        if (i >= K or i + K < N) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        } else {
            ok &= (s[i] == t[i]);
        }
    }
    cout << (ok and count(cnt.begin(), cnt.end(), 0) == 26 ? "YES" : "NO") << endl;
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

First check: if they have the same amount of letters
Second check: check which letters need to be swapped

if (2*K <= N)
    cout << "YES" << endl;

Look at all the connected components and check if they have the same letters in each


*/
