#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<class T>
struct SegTree {
    static constexpr T unit = 0;
    T f(T a, T b) { return gcd(a, b); }
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

    vector<int> P(N);
    for (int& i : P)
        cin >> i;

    SegTree<int> st(N, (P[0] * P[N-1])/gcd(P[0], P[N-1]));
    for (int i=0; i<N; i++) 
        st.update(i, P[i]);

    long long ans1 = 0;
    int l = 0, r = N-1;
    while (l < r) {
        int lq = st.query(0, r);
        int rq = st.query(l, N-1);

        if (lq < rq) {
            ans1 += lq;
            l++;      
        } else {
            ans1 += rq;
            r--;      
        } 
    }

    long long ans2 = 0;
    l = 0, r = N-1;
    while (l < r) {
        int lq = st.query(0, r);
        int rq = st.query(l, N-1);

        if (lq <= rq) {
            ans2 += lq;
            l++;      
        } else {
            ans2 += rq;
            r--;      
        } 
    }
    cout << min(ans1, ans2) << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
