#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// WHY DOES ONE WORK BUT THE OTHER TLES???>SDL>FKJSDLKJFSKLDJFKLJSDKLFJSDLFJK
//
/* 258924 */

/* Mem: 457888kb */
/* Time: 6.17s */

/* 258924 */

/* Mem: 572672kb */
/* Time: 12.97s */
void solve(){
    int n, x; cin >> n >> x;
    vector<int> cost(n), page(n);

    for (int &t : cost)
        cin >> t;
    for (int &t : page)
        cin >> t;

    vector<vector<int>> dp(x+1,vector<int>(n+1,0));
    for (int l=1; l<=n; l++){
        for (int j=0; j<=x; j++){
            dp[j][l] = dp[j][l-1];
            int left = j-cost[l-1];
            if (cost[l-1] <= x and left >= 0){
                dp[j][l] = max(dp[j][l], page[l-1] + dp[left][l-1]);
            }
        }
    }
    cout << dp[x][n] << endl;
}
void solve1(){
    int n, x; cin >> n >> x;
    vector<int> cost(n), page(n);

    for (int &t : cost)
        cin >> t;
    for (int &t : page)
        cin >> t;

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for (int l=1; l<=n; l++){
        for (int j=0; j<=x; j++){
            dp[l][j] = dp[l-1][j];
            int left = j-cost[l-1];
            if (cost[l-1] <= x and left >= 0){
                dp[l][j] = max(dp[l][j], page[l-1] + dp[l-1][left]);
            }
        }
    }
    cout << dp[n][x] << endl;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

   	int t=1;
   	while(t--){
   		solve1();
   	}
}
