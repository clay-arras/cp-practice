#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

const long long MX = 1e9;
struct segTree {
    vector<long long> tree;
    long long size;

    void init(long long n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2*size, 0LL);
    }
    void set(long long v, long long pos, long long x, long long lx, long long rx){
        if (rx - lx == 1){
            tree[x] = v;
            return;
        }
        long long m = (lx + rx)/2;
        if (pos < m)
            set(v, pos, 2*x + 1, lx, m);
        else
            set(v, pos, 2*x + 2, m, rx);

        tree[x] = min(tree[2*x+1], tree[2*x+2]);
    }
    void set(long long v, long long pos){
        set(v, pos, 0, 0, size);
    }
    long long range(long long l, long long r, long long x, long long lx, long long rx){
        if (rx <= l or lx >= r)
            return MX;
        else if (l <= lx and r >= rx)
            return tree[x];

        long long m = (lx + rx)/2;
        long long s1 = range(l, r, 2*x+1, lx, m);
        long long s2 = range(l, r, 2*x+2, m, rx);
        return min(s1, s2);
    }
    long long range(long long l, long long r){
        return range(l, r, 0, 0, size);
    }
};

void solve (){
    long long n, q; cin >> n >> q;
    segTree s;
    s.init(n);

    for (long long i=0; i<n; i++){
        long long t; cin >> t;
        s.set(t, i);
    }

    while (q--){
        long long opt; cin >> opt;
        if (opt == 1){
            long long k, u; cin >> k >> u;
            s.set(u, k-1);
        }else{
            long long a, b; cin >> a >> b;
            cout << s.range(a-1, b) << endl;
        }
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--){
        solve();
    }
}
