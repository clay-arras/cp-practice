#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

const int MX = 1e6+6;
const int mod = 1e9+7;
long long dp[MX];


void solve(){
    int n; cin >> n;
    // each dp[n] is the number of unique ways to sum up to that n

    dp[0] = 0;
    for (int i=1; i<=6; i++){
        dp[i] = (1 << (i-1));
    }
    for (int i=7; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6];
        dp[i] %= mod;
    }
    cout << dp[n] << endl;

    // when n < 6 then we do it manually
    // when n > 6 then we use algo
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t=1;
   	while(t--){
   		solve();
   	}
}
