#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N; cin >> N;

    vector<pair<int, int>> a;
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        a.push_back({t, i});
    }
    sort(a.rbegin(), a.rend());

    // Count everything first
    // We need a way to keep track of which one is used, but also find the biggest value that is unused
    // Use a set

    set<int> p, q;
    for (int i=1; i<=N; i++)
        p.insert(-i), q.insert(-i);

    vector<pair<int, int>> ans(N, {-1, -1});
    for (int i=0; i<N; i++) {
        if (p.count(-a[i].first)) {
            ans[i].first = a[i].first;
            p.erase(-a[i].first);
        } else if (q.count(-a[i].first)) {
            ans[i].second = a[i].first;
            q.erase(-a[i].first);
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i=0; i<N; i++) {
        if (ans[i].first == -1) {
            int currV = ans[i].second;
            if (p.empty()) {
                cout << "NO" << endl;
                return;
            } else {
                auto it = p.lower_bound(-currV);
                if (it == p.end()) {
                    cout << "NO" << endl;
                    return;
                }
                ans[i].first = -(*it);
                p.erase(*it);
            }
        } else {
            int currV = ans[i].first;
            if (q.empty()) {
                cout << "NO" << endl;
                return;
            } else {
                auto it = q.lower_bound(-currV);
                if (it == q.end()) {
                    cout << "NO" << endl;
                    return;
                }
                ans[i].second = -(*it);
                q.erase(*it);
            }
        }
    }
    cout << "YES" << endl;

    vector<pair<int, pair<int, int>>> srt(N);
    for (int i=0; i<N; i++) {
        srt[i].first = a[i].second;
        srt[i].second = ans[i];
    }
    sort(srt.begin(), srt.end());

    for (auto t : srt)
        cout << t.second.first << " ";
    cout << endl;
    for (auto t : srt)
        cout << t.second.second << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

// [1]
// [2, 3, 4, 5, 5]
// [1, 1]
//
// [2, 3, 4, 5, 5]
// 2: 2 (1-2)
// 3: 3 (1-3)
// 4: 4 (1-4)
// 5: 5 (1-5)
// 5: 5 (1-5)
//
// 1 2 3 4 5
// 0 1 1 1 2
//
// 2: 2 1
// 3: 3 1
// 4: 4 2
// 5: 5 3
// 5: 5 4
//
// 2: 2 1
// 3: 3 2
// 4: 4 3
// 5: 1 5
// 5: 5 4
//
// Impossible cases:
// - More than 2
//
// Notes:
// Can't repeat the same number twice
// Can't have two 1s
// Can have two 2s, but can't have any ones
//
// PROP SOL: Greedy
// - Sort the array biggest to smallest
// - Since smaller values always work, we look for the biggest value that can fit
// - If we use up all the values, then it's impossible
// - Problem: might not be a permutation
// - Solution: instead of counting aggregated values, do one for each side
//
// 1: 1 1
// 2: 2 (1-2)
// 3: 3 (1-3)
