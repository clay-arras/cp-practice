#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N; cin >> N;

    vector<int> p(N);
    for (auto& i : p)
        cin >> i;

    vector<long long> dp(N, 0);
    dp[N-1] = 1;
    dp[N-2] = 1 + 1*(p[N-2] > p[N-1]) + dp[N-1];
    for (int r=N-1-2; r>=0; r--)
        dp[r] = (N - r) + ((p[r] > p[r+1]) ? dp[r+1] : dp[r+2]);
    //  dp[r] = 1 + (N-1-r)*((p[r+1] > p[r+2]) + 0 + (p[r] > p[r+1])) + dp[r+2];


    long long sum = 0;
    for (long long i : dp)
        sum += i;

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}


