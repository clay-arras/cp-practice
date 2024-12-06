#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debugFunc.h"
#else
#define debug(...) 42
#endif

const long long MOD = 1e9+7;

long long findProductSum(vector<long long> A) {
    long long ans = 0, sum = 0;
    for (long long i : A) {
        ans += (sum * i) % MOD;
        ans %= MOD;
        sum += i;
        sum %= MOD;
    }
    return ans;
}

long long modInverse(long long A, long long M) {
    long long m0 = M;
    long long y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        long long q = A / M;
        long long t = M;

        M = A % M, A = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}


void solve() {
    int N; cin >> N;
    vector<long long> A(N);
    for (long long& i : A)
        cin >> i;

    cout << (findProductSum(A) * 1LL * modInverse((N*1LL*(N-1)/2), MOD)) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
