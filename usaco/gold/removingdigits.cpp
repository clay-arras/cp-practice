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
vector<int> dp(MX, 1e9+9);

void solve(){
    int n; cin >> n;

    dp[n] = 0;
    for (int i=n; i>=0; i--){
        vector<int> a;
        int cp = i;
        while (cp) {
            a.push_back(cp % 10);
            cp /= 10;
        }

        for (int j=0; j<(int)a.size(); j++){
            if (i-a[j] >= 0)
                dp[i-a[j]] = min(dp[i-a[j]], dp[i]+1);
        }
    }
    cout << dp[0] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t=1;
   	while(t--){
   		solve();
   	}
}
