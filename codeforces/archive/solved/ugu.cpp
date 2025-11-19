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

    int cnt = 0;
    bool ok = false;
    for (int i=1; i<N; i++) {
        if (s[i-1] == '1' and s[i] == '0')
            ok = true;
        if (s[i] != s[i-1] and ok)
            cnt++;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--){
        solve();
    }
}

/*

Observations:
- Case 1: 000000
- Case 2: 111111
- Case 3: 000111


Prefix sum
Count total number of 1s and 0s

for (int i=0; i<N; i++) {

}

Wrong question

3
101
4
1100
5
11001
6
100010
10
0000110000
7
0101010


101
2

10
1

101
2

1010
3

010
10
1

0101010
101010
5

All preceding zeroes are ignored
All consecutive values can be treated as one
 */
