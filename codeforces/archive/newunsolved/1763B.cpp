#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, K; cin >> N >> K;
    vector<pair<int, int>> M;

    vector<int> H;
    for (int i=0; i<N; i++) {
        int h; cin >> h;
        H.push_back(h);
    }
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        M.push_back({H[i], t});
    }
    sort(M.begin(), M.end());

    int currMin = 1e9;
    vector<int> minPow(N);
    for (int i=N-1; i>=0; i--) {
        currMin = min(currMin, M[i].second);
        minPow[i] = currMin;
    }

    set<pair<int, int>> s;
    for (int i=0; i<N; i++) {
        s.insert({M[i].first, i});
    }

    auto it = s.begin();
    long long k = K, totDmg = 0, maxH = (*s.rbegin()).first;
    while (k > 0 and totDmg < maxH) {
        totDmg += k;
        it = s.upper_bound({totDmg, INT_MAX});
        if (it == s.end())
            break;
        k -= minPow[it->second];
    }
    cout << (totDmg >= maxH ? "YES" : "NO") << endl;
}

// Algorithm: we keep a sorted array of the monsters by health
// We keep a total damage. every time we attack we add k to our total damage and we move up the array to index 'i'
// There, the monsters reduce our k by the weakest power 'p' still alive
// Make a rmq...esque to keep track of the power

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
