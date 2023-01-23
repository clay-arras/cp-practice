#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve(){
    int N; cin >> N;
    vector<int> x(N);

    int MX=0;
    for (int i=0; i<N; i++){
        cin >> x[i];
        MX += x[i];
    }
    x.push_back(0);
    sort(x.begin(), x.end());

    vector<vector<int>> dp(MX+3, vector<int> (N+1, 0));
    for (int i=0; i<N; i++){
        dp[x[i]][i] = 1;
    }

    // 10, 12, 0
    set<int> st;
    for (int s=0; s<=MX; s++){
        for (int n=1; n<=N; n++){
            dp[s][n] = max(dp[s][n], dp[s][n-1]);
            // For all values in this new sum, we can add the newest n unlocked to all of them
            if (dp[s][n-1] == 1){
                if (s+x[n] <= MX){
                    dp[s+x[n]][n] = 1;
                    st.insert(s+x[n]);
                }
            }
            // We can only use each coin once, so we have to keep track of which coin we're using
            // DP[S][N] is the Sum we are on vs the Number of coins we're using (in order)
        }
    }
    /* for (int i=0; i<MX; i++) */
        /* cout << i << " " << dp[i] << endl; */
    cout << (int)st.size() << endl;
    for (int i : st)
        cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
