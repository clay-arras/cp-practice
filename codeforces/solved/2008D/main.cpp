#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debugFunc.h"
#else
#define debug(...) 42
#endif

struct DSU {
    vector<int> e, b;
    void init(int N, string s) {
        e = vector<int>(N,-1);
        b = vector<int>(N, 0);
        for (int i=0; i<N; i++) {
            if (s[i]-'0' == 0)
                b[i] = 1;
        }
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
        b[x] += b[y];
        return 1;
    }
};

void solve() {
    int N; cin >> N;
    vector<int> P(N);
    for (int& i : P)
        cin >> i;
    string s; cin >> s;

    DSU d; d.init(N, s);
    for (int i=0; i<N; i++)
        d.unite(i, P[i]-1);

    for (int i=0; i<N; i++)
        cout << d.b[d.get(i)] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
