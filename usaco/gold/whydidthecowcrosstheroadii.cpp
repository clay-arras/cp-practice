#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 1e3+4;
int dp[MX][MX];
void solve() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int& t : A)
        cin >> t;
    for (int& t : B)
        cin >> t;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1],
                        dp[i - 1][j - 1] + (abs(A[i-1] - B[j-1]) <= 4)});
        }
    }
    cout << dp[N][N] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

/*
dp[i][j] is the maximum amount of crosswalks that can be drawn if we only use the first I and first J fields


*/
