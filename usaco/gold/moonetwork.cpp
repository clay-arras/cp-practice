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

template<class T> T
Kruskals (long long N, vector<pair<T, pair<long long, long long>>> e) {
    sort(e.begin(), e.end());
    DSU D; D.init(N+1);
    T ans = 0;
    for (auto &a : e) {
        if (D.unite(a.second.first, a.second.second))
            ans += a.first;
    }
    return ans;
}

const long long MX_Y = 10;
long long dist(pair<long long, long long> a, pair<long long, long long> b) {
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}
void solve() {
    long long N; cin >> N;

    vector<pair<long long, long long>> C(N);
    for (auto& [f, s] : C)
        cin >> f >> s;
    sort(C.begin(), C.end());

    vector<pair<long long, long long>> last(MX_Y+1);
    vector<pair<long long, pair<long long, long long>>> e;
    for (long long i=0; i<N; i++) {
        for (long long j=0; j<=MX_Y; j++) {
            long long d = dist(C[i], {last[j].first, j});
            e.push_back({d, {last[j].second, i}});
        }
        last[C[i].second] = {C[i].first, i};
    }
    cout << Kruskals(N, e) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*

Naive solution: O(N^2), get all the edges and run Kruskals

40, 10
49, 1
62, 7
63, 4
72, 0
77, 2
83, 10
86, 6
90, 3
93, 4

33399824247
38658498854

*/
