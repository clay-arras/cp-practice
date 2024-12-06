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
    int a, b, c;

    cout << "? 0 0" << endl;
    cout.flush();
    cin >> a;

    cout << "? 0 " << M << endl;
    cout.flush();
    cin >> b;

    cout << "? " << N << " " << M << endl;
    cout.flush();
    cin >> c;

    a++, b++, c++;
    map<pair<int, int>, int> m;
    for (int i=1; i<=a; i++)
        m[{i, a}]++;
    for (int j=1; j<=a; j++)
        m[{a, j}]++;
    m[{a, a}]--;

    for (int i=1; i<=b; i++)
        m[{i, M-b+1}]++;
    for (int j=M; j>=b; j--)
        m[{b, j}]++;
    m[{b, M-b+1}]--;

    for (int i=N; i>=N-c; i--)
        m[{i, M-c+1}]++;
    for (int j=M; j>=M-c; j--)
        m[{N-c+1, j}]++;
    m[{N-c+1, M-c+1}]--;

    for (auto [k, v] : m) {
        if (v == 3) {
            cout << "! " << k.first << " " << k.second << endl;
            cout.flush();
            return;
        }
    }
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
