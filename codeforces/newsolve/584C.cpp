#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, T; cin >> N >> T;
    string s1, s2; cin >> s1 >> s2;

    int same = 0, diff = 0;
    for (int i=0; i<N; i++)
        (s1[i] == s2[i] ? same : diff)++;

    if ((diff+1)/2 > T or T > diff-2+1+same) {
        cout << -1 << endl;
        return;
    }
    cout << -1 << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*

Keep track of Sames and Diffs

t1, t2
Same:
- t1++, t2++ (make it different from both)
- t1, t2 (make it same as both)

Diff:
- t1++ (make it the same as s2)
- t2++ (make it the same as s1)
- t1++, t2++ (make it the same as s2)

If Diff is odd, then we do (1+Diff/2) at the very least
If T is smaller then it's impossible
If it's greater, then we can increase that value up to Diff-2+1+Same



We can ignore sames but
*/
