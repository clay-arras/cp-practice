#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

unordered_map<char, int> sums;
vector<bool> visited;
vector<char> curr_pt;
vector<int> A;

char dfs(int x) {
    visited[x] = true;
    if (curr_pt[x] != '\0')
        return curr_pt[x];

    if (!visited[A[x]])
        return dfs(A[x]);
    else return '\0';
}

void solve() {
    int N; cin >> N;

    A = vector<int>(N);
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        --t;
        A[i] = t;
    }

    int M; cin >> M;
    curr_pt = vector<char>(N, '\0');

    for (int i=0; i<M; i++) {
        int t; cin >> t;
        --t;
        char c; cin >> c;
        
        curr_pt[t] = c;
        sums.clear();
        for (int i=0; i<N; i++) {
            visited = vector<bool>(N, false);
            sums[dfs(i)]++;
        }
        cout << sums['C'] << " " << sums['O'] << " " << sums['W'] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
