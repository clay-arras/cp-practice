#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// All we really care about is which doors are going to be opened
// K is how many used, dp[i][k] = min_val
const int mxV = 1e7 + 7;
void solve(){
    int N, K; cin >> N >> K;

    // Double r to make it circular
    vector<int> r(2*N);
    for (int i=0; i<N; i++){
        int t; cin >> t;
        r[i] = t;
        r[i+N] = t;
    }

    // Two actions: end the partition and add one, or continue on with the next one
    // We need a sum variable -- how often does it change

    // Initial value
    vector<vector<int>> dp
        (2*N, vector<int> (K, mxV));

    /* dp[0][0] = 0; */
    for (int k=0; k<K; k++){
        int sum = 0, it = 0;

        for (int i=0; i<2*N; i++){
            dp[i][k+1] = min(dp[i][k+1], dp[i][k] + sum);
            sum += it*r[i];
            it++;
        }
    }

    int ans = mxV;
    for (int i=0; i<2*N; i++){
        ans = min(ans, dp[i][K-1]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}

