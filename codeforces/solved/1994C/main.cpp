#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long N, X; cin >> N >> X;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    unordered_map<int, long long> dp;
    deque<int> wind;
    long long sum = 0, ans = 0;
    for (int l=N-1; l>=0; l--) { 
        wind.push_front(A[l]);
        sum += A[l];

        while (sum > X) {
            sum -= wind.back();
            wind.pop_back();
        }
        dp[l] = dp[l+(int)wind.size()+1] + (int)wind.size();
        ans += dp[l];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
