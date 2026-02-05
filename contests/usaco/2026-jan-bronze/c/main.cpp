#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    int K; cin >> K;

    int Q; cin >> Q;
    int prev_max = -INT_MAX;

    unordered_map<int, int> ms;
    vector<vector<int>> grid(N, vector<int> (N, 0));
    while (Q--) {
        int r, c, v; cin >> r >> c >> v;
        --r, --c;

        int old_val = grid[r][c];
        grid[r][c] = v;

        for (int mi=max(0, r-K+1); mi<r+1; mi++) {
            for (int mj=max(0, c-K+1); mj<c+1; mj++) {
                ms[mi*N*N + mj] += grid[r][c] - old_val;
                prev_max = max(prev_max, ms[mi*N*N + mj]);
            }
        }
        cout << prev_max << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();
}
