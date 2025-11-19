#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;

    int ans = a;
    int mood = a;
    int jokes = a+b+c+d;

    if (a)
        ans += 2*min(b, c);
    ans += min(a, d);

    mood = max(0, mood-d);
    ans += min(mood, max(b, c) - min(b, c));
    if (jokes - ans > 0)
        ans++;

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
/* 0 1 1 0 */
