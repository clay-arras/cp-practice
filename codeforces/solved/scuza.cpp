#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

int Q;
vector<long long> pref, max_pref;
bool ok(int i) {
    return Q >= max_pref[i];
}
int last_true(int lo, int hi, function<bool(int)> f) {
	lo--;
	for (int dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && f(lo + dif)) { lo += dif; }
	}
	return lo;
}

void solve() {
    int n, q; cin >> n >> q;

    vector<long long> a(n), b(q);
    for (long long& t : a)
        cin >> t;
    for (long long& t : b)
        cin >> t;

    pref = vector<long long>(n+1, 0);
    max_pref = vector<long long>(n);
    max_pref[0] = a[0];
    for (int i=0; i<n; i++) {
        pref[i+1] = pref[i] + a[i];
        if (i != 0)
            max_pref[i] = max(max_pref[i-1], a[i]);
    }

    for (int i=0; i<q; i++) {
        Q = b[i];

        int val = last_true(0, n-1, ok);
        cout << pref[val+1] << " ";
    }
    cout << endl;
}

// First number in array strictly greater than k
// Prefix sum
// Need to be independent answers, otherwise use two pointer method
// Max prefix sum
// val > thisval[i]

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

