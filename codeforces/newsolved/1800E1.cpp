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

    bool ans = true;
    vector<int> m(26, 0);
    for (int i=0; i<N; i++) {
        if (i+K<N or i>=K) {
            m[s[i]-'a']++;
            m[t[i]-'a']--;
        } else if (s[i] != t[i])
            ans &= false;
    }
    ans &= (count(m.begin(), m.end(), 0) == 26);
    cout << (ans ? "YES" : "NO") << endl;
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
