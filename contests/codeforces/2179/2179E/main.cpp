#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long N, X, Y; cin >> N >> X >> Y;
    string s; cin >> s;
    vector<int> P(N);
    for (int& i : P)
        cin >> i;

    long long xsum = 0, ysum = 0;
    int xleft = 0, yleft = 0;
    for (int i=0; i<N; i++) {
        int a, b;
        if (P[i] % 2) {
            a = ceil(P[i]*1.0/2);
            b = floor(P[i]*1.0/2);
        } else {
            a = P[i]/2 + 1;
            b = P[i]/2 - 1;
        }
        if (s[i] == '1')
            swap(a, b);

        xsum += a;
        ysum += b;

        if (s[i] == '0') yleft += (a - 1);
        else xleft += (b - 1);
    }
    sort(s.begin(), s.end());
    if (s[0] != '0' || s[N-1] != '1') {
        if (s[0] == '0') {
            // if (X-xsum < Y-yleft) {
            if ((X-xsum) < (Y-ysum)) {
                cout << "NO" << endl;
                return;
            }
        } else {
            if (Y-ysum < X-xsum) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << (xsum <= X && ysum <= Y ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
