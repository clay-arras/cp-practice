#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 1e5+5;
const long long mxV = 1e18+9;
int N, M;
int C[MX], S[MX], F[MX];
vector<int> adj_list[MX];


bool canVisit(int src = 0) {
    vector<int> c[N];
    vector<bool> keys(N, false);

    queue<int> q;
    while (!q.empty()) {
        int x = q.top(); q.pop();

        for (int t : adj_list[x])
            c[C[t]].push_back(t);

        keys[x[src]] = true;
        for (int t : c[S[x]]) {

        }
    }


}

void solve() {
    cin >> N >> M;
    for (int i=0; i<N; i++)
        cin >> C[i], C[i]--;
    for (int i=0; i<N; i++)
        cin >> S[i], S[i]--;
    for (int i=0; i<N; i++)
        cin >> F[i], F[i]--;

    for (int j=0; j<M; j++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    fill(C, C+N, 0);
    fill(S, S+N, 0);
    fill(F, F+N, 0);
    for (int i=0; i<N; i++)
        adj_list[i].clear();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int T; cin >> T;
    while (T--) {
        solve();
    }
}
