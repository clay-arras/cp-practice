#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// Important variables: total sum of N, which cow we are on, which group we are on
// Groups: how many in group, max value in group, which Kth we are on
// Actions: end group & start a new one, add cow

void solve(){
    int N, K; cin >> N >> K;

    vector<int> s(N), dp(N+1e2);
    for (int i=0; i<N; i++){
        cin >> s[i];
    }

    dp[0] = s[0];
    for (int i=1; i<N; i++){
        int mV = s[i];

        for (int j=i; j>=0 and i+1-j<=K; j--){
            mV = max(mV, s[j]);
            if (j==0){
                dp[i] = max(dp[i], mV*(i+1));
            }else{
                dp[i] = max(dp[i], dp[j-1] + mV*(i+1-j));
            }
        }
    }
    cout << dp[N-1] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int t=1;
    while(t--){
        solve();
    }
}
