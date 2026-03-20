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
    pair<int, int> mn = {INT_MAX, -1};
    
    vector<pair<int, int>> m;
    set<pair<int, int>> s;
    for (int i=0; i<N; i++)
        s.insert({P[i], i});

    int ans = 0;
    for (int i=0; i<N; i++) {
        s.erase({P[i], i});
        if (mn.first != INT_MAX && P[i] > mn.first && d.get(mn.second) != d.get(i)) {
            ans += d.unite(mn.second, i);
            m.push_back({mn.second, i});
        }
        if (!s.empty() && s.rbegin()->first > P[i] && d.get(s.rbegin()->second)
                != d.get(i)) {
            ans += d.unite(s.rbegin()->second, i);
            m.push_back({s.rbegin()->second, i});
        }
        mn = min(mn, {P[i], i});
    }

    if (ans == N-1) {
        cout << "Yes" << endl;
        // for (int i=0; i<N-1; i++)
        //     cout << m[i].first << " " << m[i].second << endl;
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
