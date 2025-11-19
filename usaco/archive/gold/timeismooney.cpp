#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 2e3+5;
vector<int> arr_list[MX];

void solve(){
    int N, M, C; cin >> N >> M >> C;
    vector<int> m(N);

    for (int &t : m)
        cin >> t;

    for (int i=0; i<M; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        arr_list[u].push_back(v);
    }


    vector<vector<int>> dp(N, vector<int>(MX+1, -1));
    dp[0][0] = 0;

    int ans = 0;
    for (int i=0; i<MX; i++){
        int scost = C*(2*(i+1)-1);
        for (int j=0; j<N; j++){
            if (dp[j][i] != -1){
                for (int u : arr_list[j])
                    dp[u][i+1] = max(dp[u][i+1], dp[j][i] + m[u] - scost);
            }
        }
        ans = max(ans, dp[0][i]);
    }

    cout << ans << endl;

    // important variables: days, money made, city on
    // dp[city on][days] = money made

    // for each city on, dp[next city][days+1] = max(dp[next city][days+1], dp[city][days] + money[city] - subcost)
    // subtract cost = c*(2*days - 1)
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}
