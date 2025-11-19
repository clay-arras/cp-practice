#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

vector<bool> visited;
vector<int> A, topo;
int N;
vector<long long> C;

vector<int> back;
vector<pair<int, int>> cycles;
bool ok;

const long long MX = LLONG_MAX;

void dfs1(int t) {
    visited[t] = true;
    if (!visited[A[t]])
        dfs1(A[t]);
    topo.push_back(t);
}

void dfs2(int t) {
    back[t] = 1;
    if (back[A[t]] == 0)
        dfs2(A[t]);
    else if (back[A[t]] == 1 && t != A[t])
        cycles.push_back({t, A[t]});
    back[t] = 2;
}

void topo_sort() {
    visited = vector<bool>(N, false);
    for (int i=0; i<N; i++)
        if (!visited[i])
            dfs1(i);
    reverse(topo.begin(), topo.end());
}

vector<vector<long long>> solve_subp() {
    topo_sort();

    unordered_map<int, vector<int>> ch;
    for (int i=0; i<N; i++)
        ch[A[i]].push_back(i);

    vector<vector<long long>> dp(N, vector<long long>(2, MX));
    for (int i=0; i<N; i++) { // base case
        if (ch[i].empty()) {
            dp[i][0] = 0;
            dp[i][1] = C[i];
        }
    }
    for (int i=0; i<N; i++) {
        int idx = topo[i];

        bool ld = false;
        for (int j : ch[idx])
            if (j == idx)
                ld = true;

        long long sum = 0;
        for (int j : ch[idx]) // transition 1
            if (j != idx)
                sum += dp[j][1];
        dp[idx][0] = min(dp[idx][0], ld ? MX : sum);

        long long pref = 0;
        for (int j : ch[idx]) // transition 2
            if (j != idx)
                pref += min(dp[j][0], dp[j][1]);
        dp[idx][1] = min(dp[idx][1], ld ? pref : C[idx] + pref);
    }
    return dp;
}

void solve() {
    cin >> N;

    A = vector<int>(N);
    C = vector<long long>(N);
    for (int& i : A)
        cin >> i;
    for (int i=0; i<N; i++) A[i]--;
    for (long long& i : C)
        cin >> i;

    vector<int> orig = A;
    back = vector<int>(N, 0);
    for (int i=0; i<N; i++)
        if (!back[i])
            dfs2(i);

    for (auto c : cycles)
        A[c.first] = c.first;
    auto dp1 = solve_subp();

    A = orig;
    for (auto c : cycles)
        A[c.second] = c.second;
    auto dp2 = solve_subp();


    long long ans = 0;
    for (int i=0; i<N; i++) {
        if (orig[i] == i) {
            assert(dp1[i][1] == dp2[i][1]);
            ans += dp1[i][1];
        }
    }
    for (auto c : cycles)
        ans += min(dp1[c.first][1] + C[c.first], dp2[c.second][1] + C[c.second]);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}

/*
subproblem 1: ai >= i; in other words, there are no cycles and we can do it normally.
steps: topo sort then dp process
*/
