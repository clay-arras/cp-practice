#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<class T>
struct RMaxQ {
    vector<T> v; vector<vector<int>> jmp;
    int level(int x) { return 31-__builtin_clz(x); }
    int cmb(int a, int b) {
        if (v[a] == v[b])
            return max(a, b);
        return v[a] > v[b] ? a : b;
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


template<class T>
struct RMinQ {
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

void solve() {
    int N; cin >> N;

    vector<int> A(N);
    for (int& t : A)
        cin >> t;

    RMinQ<int> mn;
    mn.init(A);
    RMaxQ<int> mx;
    mx.init(A);

    int l = 0, r = N-1;
    while (l < r) {
        int mnV = mn.query(l, r);
        int mxV = mx.query(l, r);

        int ll = l, rr = r;
        if (A[ll] == mxV or A[ll] == mnV)
            l++;
        if (A[rr] == mxV or A[rr] == mnV)
            r--;
        if (A[ll] != mxV and A[ll] != mnV and A[rr] != mnV and A[rr] != mxV) {
            cout << ll+1 << " " << rr+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
