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

const int MX = 1e6+9;
void solve(){
    int n, x; cin >> n >> x;
    int a[MX];
    vector<int> dp(MX, 1e9);

    for (int i=0; i<n; i++){
        cin >> a[i];
        dp[a[i]] = 1;
    }

    dp[0] = 0;
    for (int i=1; i<=x; i++){
        for (int j=0; j<n; j++){
            if (i-a[j] >= 0){
                dp[i] = min(dp[i], dp[i-a[j]]+1);
            }
        }
    }

    if (dp[x] == 1e9){
        dp[x] = -1;
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
