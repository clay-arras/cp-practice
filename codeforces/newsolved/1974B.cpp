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

    string r = "";
    map<char, int> m;

    for (char c : s) {
        if (!m[c])
            r += c;
        m[c]++;
    }
    sort(r.begin(), r.end());
    map<char, char> m2;

    for (int i=0, len=(int)r.size(); i<len; i++) {
        m2[r[i]] = r[len-i-1];
    }
    string ans = "";
    for (int i=0; i<N; i++) {
        ans += m2[s[i]];
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

/*



*/
