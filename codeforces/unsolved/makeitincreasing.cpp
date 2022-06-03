#include <bits/stdc++.h>
using namespace std;

/* #define cerr if(0) cerr */
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

const int MX = 5e3 + 4;
vector<int> dp(MX, 1e9+4);

void cope() {
    int n; cin >> n;

    set<int> a;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.insert(t);
    }
    dp[0] = 0;

    for (int i=0; i<n; i++){
        for (auto it = a.begin(); it != a.end(); ++it){
            if (i + *it < n){
                dp[i+*it] = min(dp[i+*it], dp[i] + 1);
            }
            if (i - *it > 0){
                dp[i-*it] = min(dp[i-*it], dp[i] + 1);
            }
        }
    }


    sort(dp.begin(), dp.end());
    int ans=0;
    for (int i=0; i<n; i++){
        ans += dp[i];
        n--;
        if (n == 0){ break; }
        ans += dp[i];
        n--;
    }
    cout << ans << endl;
}

void solve(){
    int n; cin >> n;
    vector<int> a;

    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.push_back(t);
    }
    // where to put the 0
    // possible greedy solution: simply find the max and make that the pivot point
    // if multipe then do the middle one


}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);

    int t; cin >> t;
    while (t--){
        solve();
    }
}
