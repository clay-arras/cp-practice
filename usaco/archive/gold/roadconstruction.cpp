#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct DSU {
    long long mx;
    vector<long long> e, h;
    vector<int> ht;
    unordered_set<int> s;
    DSU(int N){
        for (int i=0; i<N; i++){
            e.push_back(i);
           s.insert(i);
            h.push_back(1);
            ht.push_back(0);
        }
        mx = 1;
    }

    int find(int s){
        if (s != e[s])
            s = find(e[s]);
        return e[s];
    }

    void merge(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB)
            return;

        int sum = h[rootA] + h[rootB];
        if (ht[rootA] > ht[rootB]) {
            e[rootB] = rootA;
            s.erase(rootB);
            h[rootA] = sum;
            h[rootB] = sum;

            mx = max(mx, h[rootA]);
            ht[rootA] = max(ht[rootA], ht[rootB] + 1);
        } else {
            e[rootA] = rootB;
            s.erase(rootA);
            h[rootB] = sum;
            h[rootA] = sum;

            mx = max(mx, h[rootB]);
            e[rootA] = rootB;
            ht[rootB] = max(ht[rootB], ht[rootA] + 1);
        }
    }
};

void solve(){
    int n, m; cin >> n >> m;
    DSU d(n);
    while(m--){
        int u, v; cin >> u >> v;
        --u, --v;
        d.merge(u, v);
        cout << (int)d.s.size() << " " << d.mx << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
