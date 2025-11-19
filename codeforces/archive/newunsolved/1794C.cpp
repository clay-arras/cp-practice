#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

int k;
vector<int> A;
bool ok(int x) {
    return A[x]*1.0/(k-x+1) < 1;
}

template<class T>
T lastTrue(T lo, T hi, function<bool(int)> f) {
    lo--;
    for (T dif=hi-lo; dif>0; dif/=2) {
        while (lo + dif <= hi && f(lo + dif)) { lo += dif; }
    }
    return lo;
}

void solve() {
    int N; cin >> N;

    A = vector<int> (N);
    for (int& t : A)
        cin >> t;

    vector<int> ans(N);
    for (int i=N-1; i>=0; i--) {
        k = i;
        ans[i] = i-(lastTrue(0, i, ok));
    }
    for (int i : ans)
        cout << i << " ";
    cout << endl;
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

Two pointers, the right one points to the number we are on now, the left one points to the furthest back
We store a prefix product sum so that we can calculate it quickly
We keep moving the left one until some > condition is satisfied

*/
