#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
/* #include "debugging.h" */
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// Variables: which group we are on, the amount of times we changed nets, the size of current K = total wasted space
// - How many times are we planning on going forward
//
// When you capture C consecutive groups of snakes, the size of the net K should be the max_element(a[i], a[i] + C)
//
// Sum up all the values, then add up all the chosen values of the net size
// Maximize the values of the net size without going over
//
// Actions: change net size to current size, move on to next i
// If next one is greater than current net size then must change net size
//
// dp[i][k] = total space (MAX)
// The maximum space is the maximum value in that interval
// How do I keep track of the maximum size of the net
//
// Keep track of the maximum

void solve(){
    int N, K; cin >> N >> K;

    vector<int> a(N+1, 0);
    for (int i=1; i<=N; i++){
        cin >> a[i];
    }

    int T = 0;
    for (int t : a)
        T += t;

    vector<vector<int>> dp(N+1, vector<int> (K+1, 0));

    int max_group = -1;
    for (int i=1; i<=N; i++){
        max_group = max(max_group, a[i]);
        dp[i][0] = i*max_group;

        for (int k=1; k<=K; k++) {
            dp[i][k] = INT_MAX - 1e2;;
            int net_size = a[i];

            for (int c=i-1; c>=0; c--) {
                dp[i][k] = min(dp[i][k], dp[c][k-1] + net_size*(i - c));
                net_size = max(net_size, a[c]);
            }
        }
    }
    cout << dp[N][K] - T << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}
