#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

struct DSU{
    vector<int> e, h;
    DSU(int N){
        for (int i=0; i<N; i++){
            e.push_back(i);
            h.push_back(0);
        }
    }

    int find(int s){
        if (s != e[s])
            s = find(e[s]);
        return e[s];
    }

    void merge(int a, int b){
        int rootA = find(a);
        int rootB = find(b);

        if (h[rootA] > h[rootB]) {
            e[rootB] = rootA;
            h[rootA] = max(h[rootA], h[rootB] + 1);
        } else {
            e[rootA] = rootB;
            h[rootB] = max(h[rootB], h[rootA] + 1);
        }

    }
};

void solve(){
    int N, Q; cin >> N >> Q;

    DSU d(N);
    while (Q--){
        int op, u, v; cin >> op >> u >> v;
        if (op == 0){
            d.merge(u, v);
        }else{
            cout << (d.find(u) == d.find(v)) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--) {
        solve();
    }
}
