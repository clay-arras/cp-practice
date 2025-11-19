#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MOD = 1e9+7;
const long long MXN = 1e3+1;

long long dp[MXN];
long long fact(long long i, long long j) {
    long long val = 1;
    for (long long k=j+1; k<=i; k++)
        val *= k;
    return val % MOD;
}

void solve() {
    long long N, X, P; cin >> N >> X >> P;

    long long ans = 0;
    long long L = 0, R = 0;
    function<bool(long long)> f = [&](long long k) {
        long long l = 0;
        long long r = N;
        while (l < r) {
            long long m = (l + r) / 2;
            if (m + 1 <= k) {
                l = m + 1;
                R++;
                if (l < r)
                    R--;
            } else {
                r = m;
                L++;
                if (l < r)
                    L--;
            }
        }
        return (l > 0 && l == k);
    };

    f(P);
    ans += ((fact(X, X-L) * fact(N-X, R)) % MOD * fact(N-L-R, 0)) % MOD;
    cout << ans << endl;

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
BinarySearch(a, x)
    left = 0
    right = a.size()
    while left < right
        middle = (left + right) / 2
        if a[middle] <= x then
            left = middle + 1
        else
            right = middle

    if left > 0 and a[left - 1] == x then
        return true
    else
        return false
*/
