#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); 
    }
};

void solve() {
    int N; cin >> N;
    vector<int> P(N);
    for (int& i : P)
        cin >> i;
    string s; cin >> s;

    int x = max_element(P.begin(), P.end()) - P.begin();
    int y = min_element(P.begin(), P.end()) - P.begin();

    if (s[0] == '1' || s[N-1] == '1' || s[x] == '1' || s[y] == '1') {
        cout << -1 << endl;
        return;
    }

    unordered_set<pair<int, int>, PairHash> st;
    if (x+1 != 1)
        st.insert({1, x+1});
    if (y+1 != 1)
        st.insert({1, y+1});
    if (x+1 != N)
        st.insert({x+1, N});
    if (y+1 != N)
        st.insert({y+1, N});
    st.insert({min(x+1, y+1), max(x+1, y+1)});

    cout << (int)st.size() << endl;
    for (auto [fs, sn] : st)
        cout << fs << " " << sn << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
