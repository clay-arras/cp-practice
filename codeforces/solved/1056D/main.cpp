#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 1e5+1;
vector<int> adj_list[MX];

vector<int> lfs;
int dfs(int x) {
    assert(lfs[x] != -2);
    lfs[x] = -2; // processing

    int sum = (adj_list[x].size() == 1 && x);
    for (int t : adj_list[x]) {
        if (lfs[t] == -1)
            sum += dfs(t);
    }
    return lfs[x] = sum;
}


void solve() {
    int N; cin >> N;

    if (N == 1) {
        cout << 1 << endl;
        return;
    }
    lfs = vector<int>(N, -1);

    for (int i=1; i<=N-1; i++) {
        int p; cin >> p;
        --p;
        adj_list[p].push_back(i);
        adj_list[i].push_back(p);
    }

    dfs(0);
    sort(lfs.begin(), lfs.end());

    for (int i : lfs)
        cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}
