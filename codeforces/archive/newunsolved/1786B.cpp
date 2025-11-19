#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

int w, h;
bool isWithin(int a, int b) {
    return (a+w >= b+h and a-w <= b-h);
}

void solve() {
    long long n; cin >> n >> w >> h;

    vector<long long> a(n), b(n);
    for (long long& t : a)
        cin >> t;
    for (long long& t : b)
        cin >> t;

    long long sum = 0;
    for (int i=0; i<n; i++) {
        long long diff = a[i] - b[i];
        sum += diff;
    }

    long long val = sum/n;
    for (int i=0; i<n; i++) {
        b[i] += val;
    }

    auto func = [](int v, vector<long long> a, vector<long long> b) {
        vector<long long> c = b;
        for (auto &t : b)
            t += v;

        bool ok = true;
        for (int i=0; i<(int)a.size(); i++)
            ok &= isWithin(a[i], b[i]);

        return ok;
    };

    // This solution is cheese but whatever
    bool ok = false;
    for (int i=-5; i<=5; i++) {
        ok |= func(i, a, b);
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

// Loop through the differences in the cakes
// Each distance between the conveyors has to match up within a certain margin of error
// How do we find the perfect distance to use
