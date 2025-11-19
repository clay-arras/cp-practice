#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct Rect {
    int x1, y1, x2, y2;
    Rect unite(const Rect& other) {
        Rect ret;
        ret.x1 = max(x1, other.x1);
        ret.y1 = max(y1, other.y1);
        ret.x2 = min(x2, other.x2);
        ret.y2 = min(y2, other.y2);
        return ret;
    }
    bool valid() {
        return (x1 <= x2) && (y1 <= y2);
    }
};

template<class T>
struct RMQ {
    vector<T> v; vector<vector<int>> jmp;
    int level(int x) { return 31-__builtin_clz(x); }
    int cmb(int a, int b) {
        if (v[a] == v[b])
            return min(a, b);
        return v[a] < v[b] ? a : b;
    }
    void init(const vector<T>& _v) {
        int sz = (int)_v.size();
        jmp = { vector<int>(sz) };
        v = _v;
        iota(jmp[0].begin(), jmp[0].end(), 0);
        for (int j=1; (1<<j)<=sz; j++) {
            jmp.push_back(vector<int>(sz-(1<<j)+1));
            for (int i=0; i<(int)jmp[j].size(); i++)
                jmp[j][i] = cmb(jmp[j-1][i], jmp[j-1][i+(1<<(j-1))]);
        }
    }
    int index(int l, int r) {
        int d = level(r-l+1);
        assert(l <= r);
        return cmb(jmp[d][l], jmp[d][r-(1<<d)+1]);
    }
    T query(int l, int r) { return v[index(l,r)]; }
};

void solve1() {
    // int N; cin >> N;
    //
    // vector<Rect> bx;
    // for (int i=0; i<N; i++) {
    //     long long x1, y1, x2, y2;
    //     cin >> x1 >> y1 >> x2 >> y2;
    //     bx.push_back(Rect({x1, y1, x2, y2}));
    // }
    //
    // auto process = [&](bool incl0) {
    //     bool neg = false;
    //
    //     Rect st = (incl0 ? bx[0] : bx[1]);
    //     for (int i=0; i<N; i++) {
    //         auto next = st.unite(bx[i]);
    //         if (!next.valid() && neg)
    //             return next;
    //         if (!next.valid() && !neg) {
    //             neg = true;
    //             continue;
    //         }
    //         st = next;
    //     }
    //     return st;
    // };
    //
    // auto case1 = process(true);
    // auto case2 = process(false);
    //
    // if (case1.valid()) {
    //     cout << case1.x1 << " " << case1.y1 << endl;
    // } else if (case2.valid()) {
    //     cout << case2.x1 << " " << case2.y1 << endl;
    // } else {
    //     assert(false);
    // }
}

void solve() {
    int N; cin >> N;

    vector<int> x1, y1, x2, y2;
    for (int i=0; i<N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        x1.push_back(-a);
        y1.push_back(-b);
        x2.push_back(c);
        y2.push_back(d);
    }
    RMQ<int> x1q, y1q, x2q, y2q; // neg neg pos pos
    x1q.init(x1);
    y1q.init(y1);
    x2q.init(x2);
    y2q.init(y2);

    for (int i=0; i<N; i++) {
        int ix1 = INT_MAX, iy1 = INT_MAX;
        int ix2 = INT_MAX, iy2 = INT_MAX;
        if (0 <= i-1) {
            ix1 = min(ix1, x1q.query(0, i-1));
            iy1 = min(iy1, y1q.query(0, i-1));
            ix2 = min(ix2, x2q.query(0, i-1));
            iy2 = min(iy2, y2q.query(0, i-1));
        }
        if (i+1 <= N-1) {
            ix1 = min(ix1, x1q.query(i+1, N-1));
            iy1 = min(iy1, y1q.query(i+1, N-1));
            ix2 = min(ix2, x2q.query(i+1, N-1));
            iy2 = min(iy2, y2q.query(i+1, N-1));
        }
        Rect r{-ix1, -iy1, ix2, iy2};
        if (r.valid()) {
            cout << r.x1 << " " << r.y1 << endl;
            return;
        }
    }
    assert(-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
