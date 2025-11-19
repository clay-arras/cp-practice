#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MOD = 1e9+7;
long long bxp(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    int N; cin >> N;
    while (N--){
        long long a, b, c; cin >> a >> b >> c;
        long long bmc = bxp(b, c, MOD-1);
        cout << bxp(a, bmc, MOD) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}

