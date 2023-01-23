#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

const int MX = 1e6+6;
const int mod = 1e9+7;
long long dp[MX];

void solve(){
    int n, x; cin >> n >> x;
    vector<int> c;
    set<int> sc;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        c.push_back(t);
        sc.insert(t);
    }
    sort(c.begin(), c.end());

    for (int i=0; i<=x; i++){
        int sum = 0;
        for (int j=0; j<n; j++){
            if (i-c[j] >= 0)
                sum += dp[i-c[j]];
            sum %= mod;
        }
        if (sc.count(i))
            sum++;

        dp[i] = sum;
    }
    cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
