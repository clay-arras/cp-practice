#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, Q; cin >> N >> Q;
    
    vector<int> A(N);
    for (int& i : A) {
        cin >> i;
        --i;
    }

    vector<pair<int, int>> qu;
    for (int q=0; q<Q; q++) {
        int i, x; cin >> i >> x;
        --i, --x;
        qu.push_back({i, x});
    }

    vector<int> cnt(N, 0);
    for (int i : A)
        cnt[i]++;
    map<int, set<int>> freq;
    for (int i=0; i<N; i++)
        freq[cnt[i]].insert(i);

    for (auto [i, x] : qu) {
        int xp = A[i];
        A[i] = x;
        
        freq[cnt[x]].erase(x);
        freq[cnt[xp]].erase(xp);

        if (freq[cnt[x]].empty()) freq.erase(cnt[x]);
        if (freq[cnt[xp]].empty()) freq.erase(cnt[xp]);
        cnt[x]++;
        cnt[xp]--;

        freq[cnt[x]].insert(x);
        freq[cnt[xp]].insert(xp);

        // --- 
        
        int vmax = freq.rbegin()->first;
        auto rit = freq.rbegin();
        int mn = 1e7, mx = -1e7;

        int ans = 0;
        for (auto it=freq.begin(); it!=freq.end(); ++it) {
            while (rit != freq.rend() && next(rit, 1)->first && next(rit, 1)->first + it->first >= vmax) {
                mn = min(mn, *rit->second.begin());
                mx = max(mx, *rit->second.rbegin());
                rit = next(rit, 1);
            }
            if (rit != freq.rend() && rit->first) { // cannot equal 0
                mn = min(mn, *rit->second.begin());
                mx = max(mx, *rit->second.rbegin());
            }

            if (it->first) { // cannot equal 0
                ans = max(ans, *it->second.rbegin() - mn);
                ans = max(ans, mx - *it->second.begin());
            }
        }

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t = 1;
    while (t--) {
        solve();
    }
}
