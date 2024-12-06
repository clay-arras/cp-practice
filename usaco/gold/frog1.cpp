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

const int MX = 1e5+5;
int dp[MX];
int done[MX];
int a[MX];

int dp1(int n){
    if (done[n]) return dp[n];
    if (n==1) return 0;
    if (n==2) return abs(a[1] - a[2]);

    assert(n != 0);

    done[n] = true;
    dp[n] = min(dp1(n-1) + abs(a[n] - a[n-1]), dp1(n-2) + abs(a[n] - a[n-2]));

    return dp[n];
}

void solve(){
    int n; cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    for (int i=2; i<=n; i++){
        dp[i] = INT32_MAX;
    }
    cout << dp1(n) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t=1;
   	while(t--){
  		solve();
   	}
}



