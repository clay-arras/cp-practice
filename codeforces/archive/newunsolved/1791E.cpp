#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MX = 1e18+9;
void solve() {
    int n; cin >> n;

    long long sum=0, minV=MX, negs=0;
    for (int i=0; i<n; i++) {
        long long t; cin >> t;
        if (t < 0)
            negs++;
        sum += abs(t);
        minV = min(minV, abs(t));
    }

    cout << (negs % 2 ? sum - 2*minV : sum) << endl;
}

// If there are odd number of negative numbers, then find the smallest value
// Otherwise the answer is the sum of all of them

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

