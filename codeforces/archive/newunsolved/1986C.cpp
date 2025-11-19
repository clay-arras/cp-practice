#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, M; cin >> N >> M;
    string s; cin >> s;
    vector<int> up(M);
    for (int& i : up)
        cin >> i;
    string c; cin >> c;

    sort(c.begin(), c.end());
    map<int, int> m;
    for (int i=0; i<M; i++)
        m[up[i]-1]++;
    for (int i=0, ptr=0; i<N && ptr<M; i++) {
        if (m[i]) {
            s[i] = c[ptr];
            ptr++;
        }
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
