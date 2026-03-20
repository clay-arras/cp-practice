#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct DSU {
    vector<int> e;
    void init(int N) {
        e = vector<int>(N,-1);
    }
    int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }
    int size(int x) {
        return -e[get(x)];
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x,y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

void solve() {
    int N; cin >> N;
    vector<int> P(N);
    for (int& i : P)
        cin >> i;

    DSU d; d.init(N);   
    pair<int, int> pref = {INT_MAX, -1};

    vector<pair<int, int>> suff(N, {-INT_MAX, -1});
    for (int i=N-2; i>=0; i--) 
        suff[i] = max(suff[i+1], {P[i+1], i+1});

    vector<pair<int, int>> e;
    for (int i=0; i<N; i++) {
        if (pref.first < P[i] && d.unite(pref.second, i))
            e.push_back({pref.first, i});
        if (P[i] < suff[i].first && d.unite(i, suff[i].second))
            e.push_back({i, suff[i].second});

        pref = min(pref, {P[i], i});
    }

    cerr << e << endl;
    if ((int)e.size() == N-1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
