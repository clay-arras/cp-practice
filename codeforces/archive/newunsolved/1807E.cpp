#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

vector<int> A, pref;
bool ok(int x) {
    cout << "? " << x;
    for (int i=0; i<x; i++)
        cout << " " << i+1;
    cout << endl;

    int psum; cin >> psum;
    return (psum != pref[x-1]);
}

template<class T>
T firstTrue(T lo, T hi, function<bool(int)> f) {
    hi++;
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

void solve() {
    int N; cin >> N;

    A = vector<int> (N);
    for (int& t : A)
        cin >> t;

    pref = vector<int> (N, 0);
    pref[0] = A[0];
    for (int i=1; i<N; i++)
        pref[i] += A[i] + pref[i-1];

    int k = firstTrue(1, N, ok);
    cout << "! " << k << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    /* open("input.txt"); */

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
