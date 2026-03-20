#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<class T>
T lastTrue(T l, T r, function<bool(T)> f) {
    l--;
    for (T diff=r-l; diff>0; diff/=2)
        while (l + diff <= r && f(l + diff))
            l += diff;
    return l;
}

template<class T>
struct SegTree {
    static constexpr T unit = {true, -INT_MAX};
    T f(T a, T b) {  // first is bool, second is int
        if (a == unit)
            return {true, b.second};
        if (b == unit)
            return {true, a.second};

        bool ok = a.first && b.first && (a.second == b.second);
        return {ok, a.second}; 
    }
    vector<T> tree; int n;
    SegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}
    void update(int pos, T val) {
        for (tree[pos += n] = val; pos /= 2;)
            tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
    }
    T query(int b, int e) {
        e++;
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, tree[b++]);
            if (e % 2) rb = f(tree[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    SegTree<pair<bool, int>> smt(N);
    for (int i=0; i<N; i++)
        smt.update(i, {true, A[i]});

    vector<int> ans(N, INT_MAX);
    vector<long long> pref;
    long long roll = 0;

    vector<int> lld(N, INT_MAX);
    for (int i=1; i<N; i++)
        lld[i] = (A[i] == A[i-1] ? lld[i-1] : i-1);

    cerr << A << endl;
    cerr << lld << endl;
    for (int i=0; i<N; i++) {
        int pos = lastTrue<int>(0, i-1, [&](int t) {
            return pref[t] + roll > A[i];            
        });
        cerr << i << " " << pos << " ";

        int upd = INT_MAX;
        if (pos != -1) {
            auto res = smt.query(pos, i-1);
            cerr << res << " ";
            if (res.first && A[i-1]<=A[i]) {
                upd = (lld[pos] == INT_MAX ? INT_MAX : i - lld[pos]);
            } else {
                upd = i - pos;
            }
            // upd = (res.first && A[i-1]<=A[i] ? i - lld[pos] : i - pos);
            // if (lld[pos] == INT_MAX) 
            //     upd = INT_MAX;
        }
        cerr << endl;

        ans[i] = min(ans[i], upd);
        roll += A[i];
        pref.push_back(A[i] - roll);
    }
    cerr << endl;

    // pref.clear();
    // roll = 0;

    // vector<int> rld(N, INT_MAX);
    // for (int i=N-2; i>=0; i--)
    //     rld[i] = (A[i] == A[i+1] ? rld[i+1] : i+1);

    // for (int i=N-1; i>=0; i--) {
    //     int pos = lastTrue<int>(0, i-1, [&](int t) {
    //         return pref[t] + roll > A[i];            
    //     });

    //     int upd = INT_MAX;
    //     if (pos != -1) {
    //         int idx = N - pos - 1;
    //         auto res = smt.query(i+1, idx);
    //         upd = (res.first ? rld[idx] - i : idx - i);
    //         if (rld[idx] == INT_MAX) 
    //             upd = INT_MAX;
    //     }

    //     ans[i] = min(ans[i], upd);
    //     roll += A[i];
    //     pref.push_back(A[i] - roll);
    // }

    for (int i : ans)
        cout << (i == INT_MAX ? -1 : i) << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
