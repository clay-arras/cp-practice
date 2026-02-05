#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct DSU {
    vector<long long> e;
    void init(int N) {
        e = vector<long long>(N,-1);
    }
    int get(int x) {
        if (x == INT_MAX || e[x] == INT_MAX) return INT_MAX;
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }
    long long size(int x) {
        return -e[get(x)];
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        // if (e[x] > e[y])
        //     swap(x,y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

void solve() {
    int N; cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        --t;
        A[i] = t;
    }

    int M; cin >> M;
    vector<char> curr_pt(N+1, '\0');

    vector<pair<int, pair<char, char>>> pt;
    for (int i=0; i<M; i++) {
        int t; cin >> t;
        --t;
        char c; cin >> c;

        pt.push_back({t, {curr_pt[t], c}});
        curr_pt[t] = c;
    }

    DSU d; d.init(N+1);
    for (int i=0; i<N; i++) {
        if (curr_pt[i] == '\0') {
            if (A[i] == i) {
                A[i] = N;
                continue;
            }
            if (d.get(i) == INT_MAX || d.get(A[i]) == INT_MAX)
                continue;
            if (!d.unite(A[i], i))
                d.e[d.get(i)] = INT_MAX;
        }
    }
    unordered_map<char, long long> cnt;
    for (int i=0; i<N; i++) {
        if (d.e[i] < 0)
            cnt[curr_pt[i]] += -d.e[i];
    }

    vector<vector<long long>> ans;
    ans.push_back({cnt['C'], cnt['O'], cnt['W']});
    for (int i=M-1; i>=0; i--) {
        char prev = pt[i].second.first;
        char curr = pt[i].second.second;
        int t = pt[i].first;
        assert(d.e[t] < 0);

        if (prev == '\0') {
            long long sz = -d.e[t];
            if (d.get(A[t]) == t || d.get(A[t]) == INT_MAX) {
                d.e[t] = INT_MAX;
                cnt[curr] -= sz;
            } else {
                cnt[curr] -= sz;
                cnt[curr_pt[d.get(A[t])]] += sz;
                d.unite(A[t], t);
            }
        } else {
            long long sz = -d.e[t];
            cnt[prev] += sz;
            cnt[curr] -= sz;
        }

        curr_pt[t] = prev;
        ans.push_back({cnt['C'], cnt['O'], cnt['W']});
    }

    reverse(ans.begin(), ans.end());
    for (int i=1; i<=M; i++)
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
