#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> c;
unordered_map<int, unordered_map<int, int>> memo;

int dp(int l, int r) {
    if (memo.count(l) && memo[l].count(r))
        return memo[l][r];

    int ans = INT_MAX;
    for (int i : c) {
        if (l < i && i < r) 
            ans = min(ans, r-l + dp(l, i) + dp(i, r));
    }
    return memo[l][r] = (ans == INT_MAX ? 0 : ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    c.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> c[i];
    }

    cout << dp(0, N) << "\n";
    return 0;
}
