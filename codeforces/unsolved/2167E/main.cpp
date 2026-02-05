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

void solve() {
    int N, K, X; cin >> N >> K >> X;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;
    
    auto ok = [&](int t) -> bool {
        vector<pair<int, int>> m;
        for (int i : A) {
            m.push_back({i-t, 1});
            m.push_back({i+t, -1});
            m.push_back({i-t, 2});
            m.push_back({i+t, 2});
        }
        m.push_back({0, 2});
        m.push_back({X, 2});
        sort(m.begin(), m.end());
        cerr << t << " " << m << endl;

        int ans = 0;
        int swp = 0, last = -1;
        for (auto [k, v] : m) {
            cerr << ans << " " << swp << " " << last << endl;
            if (swp == 0 && k <= X && k >= 0) {
                if (last != -1)
                    ans += k - last + 1;
                last = k;
            }
            swp += (v == 2 ? 0 : v);
        }
        cerr << ans << endl;
        return (ans >= K);
    };
    
    cerr << endl;
    cerr << endl;
    cerr << endl;
    int t = lastTrue<long long>(0LL, 40, ok);
    cerr << "ANSWER: " << t << endl;
    ok(t);
    cout << t << endl;

    // vector<pair<int, int>> m;
    // for (int i : A) {
    //     m.push_back({i-t, 1});
    //     m.push_back({i+t, -1});
    // }
    // m.push_back({0, 0});
    // m.push_back({X, 0});
    // sort(m.begin(), m.end());
    // cout << t << ": ";

    // set<int> ans;
    // int swp = 0, last = 0;
    // for (auto [k, v] : m) {
    //     if (swp == 0 && k <= X && k >= 0) {
    //         for (int j=last; j<=k && (int)ans.size() < K; j++)
    //             ans.insert(j);
    //         last = k;
    //     }
    //     swp += v;
    // }
    // for (int i : ans)
    //     cout << i << " ";
    // cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
