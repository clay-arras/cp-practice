#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MX = 1e18+9;
const int SZ = 2e5+5;
long long n, c, d;
long long pref[SZ];
int binarySearch(int lo, int hi, function<bool(int)> f) {
	lo--;
	for (int dif=hi-lo; dif>0; dif/=2) {
		while (lo + dif <= hi && f(lo + dif)) lo += dif;
	}
	return lo;
}

bool ok(long long k) {
    k = min(n, k);

    long long sumCost = 0;
    sumCost += d/k * pref[k+1];
    sumCost += pref[d%k+1];
    return sumCost >= c;
}

void solve() {
    cin >> n >> c >> d;
    cout << n << c << d;

    vector<long long> a(n);
    for (long long& t : a)
        cin >> t;

    sort(a.rbegin(), a.rend());
    fill(pref, pref+n+1, 0);
    for (int i=0; i<n; i++) {
        pref[i+1] = pref[i] + a[i];
    }
    cout << binarySearch(1, 1e5, ok) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
// 1 1 1 1 1 0 0 0 0 0

// Binary search : O(logN)
// Find the max amount of money you can make after D days
// If (N > K) then resize the array
// Then for d/k days we take the sum of the array: need a prefix sum
// Then for d%k days we take the sum of the first k: use the prefix sum from before
//
// We get the maximum cost you can make in D days
// If it takes more than K days
