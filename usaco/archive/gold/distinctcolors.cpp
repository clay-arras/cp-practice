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
    T f(T a, T b) { return a + b; }

    vector<T> tree; int n;
    SegTree (int i = 0, T def = unit) : tree(2*i, def), n(i) {}

    void update(int pos, T val) {
        for (tree[pos += n] = val; pos /= 2;)
            tree[pos] = f(tree[pos * 2], tree[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, tree[b++]);
            if (e % 2) rb = f(tree[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve(){
    int N, Q; cin >> N >> Q;

    vector<int> A(N);
    map<int, int> prev;
    vector<int> last_index(N);

    for (int i=0; i<N; i++){
        int t; cin >> t;
        A[i] = t;
        prev[t] = -1;
    }

    vector<pair<int, int>> q[N];
    for (int i=0; i<Q; i++){
        int a, b; cin >> a >> b;
        --a, --b;
        q[a].push_back({b, i});
    }

    for (int i=N-1; i>=0; i--){
        last_index[i] = prev[A[i]];
        prev[A[i]] = i;
    }

    SegTree<int> t(N+1, 0);
    set<int> s;
    for (int i=0; i<N; i++){
        int size = (int)s.size();
        s.insert(A[i]);
        if (size < (int)s.size()){
            t.update(i, 1);
        }
    }

    vector<int> ans(Q, 0);
    for (int i=0; i<N; i++){
        for (auto quer : q[i]){
            int b = quer.first, it = quer.second;
            ans[it] = t.query(i, b+1);
        }
        t.update(last_index[i], 1);
    }
    for (int i : ans)
        cout << i << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

//
