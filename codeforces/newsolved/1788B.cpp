#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif


void solve() {
    long long N; cin >> N;

    bool ok = true;
    vector<int> a, b;
    long long NP = N;
    while (NP >= 1) {
        int d = NP%10;
        if (ok) {
            a.push_back((d+1)/2);
            b.push_back(d/2);
        } else {
            a.push_back(d/2);
            b.push_back((d+1)/2);
        }
        if (d % 2 == 1) ok ^= 1;
        NP /= 10;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if ((int)a.size() == count(a.begin(), a.end(), 0)) {
        cout << 0 << " ";
    } else {
        ok = true;
        for (int i : a) {
            if (i == 0 and ok)
                continue;
            else {
                ok = false;
                cout << i;
            }
        }
        cout << " ";
    }

    if ((int)b.size() == count(b.begin(), b.end(), 0)) {
        cout << 0 << endl;
    } else {
        ok = true;
        for (int i : b) {
            if (i == 0 and ok)
                continue;
            else {
                ok = false;
                cout << i;
            }
        }
        cout << endl;
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
