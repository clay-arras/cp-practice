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
    string str; cin >> str;

    int n = 0, e = 0, s = 0, w = 0;
    for (char c : str) {
        if (c == 'N') n++;
        if (c == 'E') e++;
        if (c == 'S') s++;
        if (c == 'W') w++;
    }

    int nn = n - s, ne = e - w;
    bool ok = false;
    ok |= (nn % 2 || ne % 2);
    ok |= (N % 2);
    ok |= (!nn && !ne && N == 2);
    if (ok) {
        cout << "NO" << endl;
        return;
    }

    map<char, int> H;
    if (nn == 0 && ne == 0) {
        if (n > 0) H['N']++, H['S']++;
        else if (e > 0) H['E']++, H['W']++;
        else assert(false);
    } else {
        if (nn > 0) H['N'] += nn/2;
        if (nn < 0) H['S'] += -1*nn/2;
        if (ne > 0) H['E'] += ne/2;
        if (ne < 0) H['W'] += -1*ne/2;
    }

    string ans = "";
    for (int i=0; i<N; i++) {
        if (str[i] == 'N' && H['N'] > 0) {
            ans += 'H';
            H['N']--;
        } else if (str[i] == 'E' && H['E'] > 0) {
            ans += 'H';
            H['E']--;
        } else if (str[i] == 'S' && H['S'] > 0) {
            ans += 'H';
            H['S']--;
        } else if (str[i] == 'W' && H['W'] > 0) {
            ans += 'H';
            H['W']--;
        } else {
            ans += 'R';
        }
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
