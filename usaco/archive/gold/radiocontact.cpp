#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

long long dist(pair<long long, long long> a, pair<long long, long long> b) {
    return pow(abs(a.first - b.first), 2) + pow(abs(a.second - b.second), 2);
}
void solve() {
    int N, M; cin >> N >> M;

    vector<pair<int, int>> cF, cB;
    int x, y; cin >> x >> y;
    cF.push_back({x, y});
    cin >> x >> y;
    cB.push_back({x, y});

    string s1, s2; cin >> s1 >> s2;
    for (int i=0; i<N; i++) {
        if (s1[i] == 'N') cF.push_back({cF[i].first, cF[i].second + 1});
        if (s1[i] == 'E') cF.push_back({cF[i].first + 1, cF[i].second});
        if (s1[i] == 'S') cF.push_back({cF[i].first, cF[i].second - 1});
        if (s1[i] == 'W') cF.push_back({cF[i].first - 1, cF[i].second});
    }
    for (int i=0; i<M; i++) {
        if (s2[i] == 'N') cB.push_back({cB[i].first, cB[i].second + 1});
        if (s2[i] == 'E') cB.push_back({cB[i].first + 1, cB[i].second});
        if (s2[i] == 'S') cB.push_back({cB[i].first, cB[i].second - 1});
        if (s2[i] == 'W') cB.push_back({cB[i].first - 1, cB[i].second});
    }

    vector<vector<int>> dp(N+3, vector<int> (M+3, 1e9));
    dp[0][0] = 0;
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=M; j++) {
            int d = dist(cF[i], cB[j]);
            if (i) dp[i][j] = min(dp[i][j], dp[i-1][j] + d);
            if (j) dp[i][j] = min(dp[i][j], dp[i][j-1] + d);
            if (i and j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + d);
        }
    }
    cout << dp[N][M] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

/*
Case 1: FJ moves
Case 2: B moves
Case 3: Both move


*/
