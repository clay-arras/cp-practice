#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, M; cin >> N >> M;

    vector<int> B(N);
    for (int& i : B)
        cin >> i;
    vector<int> G(M);
    for (int& i : G)
        cin >> i;

    sort(B.rbegin(), B.rend());
    sort(G.rbegin(), G.rend());

    if (*max_element(B.begin(), B.end()) >
            *min_element(G.begin(), G.end())) {
        cout << -1 << endl;
        return;
    }

    long long min_b = 0;
    for (int i=0; i<N; i++)
        min_b += M *1LL* B[i];

    unordered_map<int, int> frees;
    for (int i : B)
        frees[i]++;

    int j = 0;
    for (int i=0; i<N; i++) {
        for (int cnt=0; cnt<M-1 && j<M; j++) {
            if (frees[G[j]]) {
                frees[G[j]]--;
                continue;
            }
            min_b += 1LL*G[j] - B[i];
            cnt++;
        }
    }
    cout << min_b << endl;
}
/*
constraints:

a) the boy can't give away his last batch greedily as it will mess up the min numbers
b) if a boys min element is == a girl's max element, then that can be used; else we throw that boy's batch away (isn't in the greedy solution)

*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}

