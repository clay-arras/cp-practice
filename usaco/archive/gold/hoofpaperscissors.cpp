#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif
map<char, int> m = {{'H', 0}, {'P', 1}, {'S', 2}};
void solve(){
    int N, K; cin >> N >> K;

    vector<char> s(N);
    for (int i=0; i<N; i++){
        char c; cin >> c;
        s[i] = m[c];
    }

    int dp[N+1][K+2][3];
    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp)/sizeof(dp[0][0][0]), 0);

    for (int i=0; i<N; i++){
        for (int j=0; j<=K; j++){
            for (int k=0; k<3; k++){
                if (k == s[i])
                    dp[i][j][k]++;

                dp[i+1][j+1][0] = max(dp[i][j][k], dp[i+1][j+1][0]);
                dp[i+1][j+1][1] = max(dp[i][j][k], dp[i+1][j+1][1]);
                dp[i+1][j+1][2] = max(dp[i][j][k], dp[i+1][j+1][2]);
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }
    cout << *max_element(dp[N][K], dp[N][K]+3) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}
