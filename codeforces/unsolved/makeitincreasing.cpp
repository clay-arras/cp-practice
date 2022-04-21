#include <bits/stdc++.h>
using namespace std;

const int MX = 5e3 + 4;
vector<int> dp(MX, 1e9+4);

void solve() {
    int n; cin >> n;

    set<int> a;
    for (int i=0; i<n; i++){
        int t; cin >> t;
        a.insert(t);
    }
    /* n--; */
    dp[0] = 0;
    /* for (auto it = a.begin(); it != a.end(); ++it){ */
    /*     /1* dp[*it] = 1; *1/ */
    /*     cout << *it << " "; */
    /* } */
    /* cout << endl; */

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

    /* for (int i=0; i<n; i++){ */
    /*     cout << i << " " << dp[i] << endl; */
    /* } */
    /* cout << endl; */

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

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);

    int t; cin >> t;
    while (t--){
        solve();
    }
}
