#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debugFunc.h"
#else
#define debug(...) 42
#endif


void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    vector<pair<int, int>> pq; // lastIndex, A[i]
    priority_queue<pair<int, int>> mn, mx; // A[i], index
    unordered_map<int, int> m;

    for (int i=N-1; i>=0; i--) {
        if (!m[A[i]]) {
            pq.push_back({-i, A[i]});
            m[A[i]]++;
        }
    }
    reverse(pq.begin(), pq.end());
    m.clear();
    vector<int> ans;

    int sz = (int)pq.size();
    for (int i=0, k=0, r=0; i<N;) {
        assert((int)mn.size() < 2*N);
        assert((int)mx.size() < 2*N);
        while (k < sz && m[pq[k].second])
            k++;
        if (k >= sz)
            break;

        while (!mn.empty() && (-mn.top().second < i || m[-mn.top().first])) mn.pop();
        while (!mx.empty() && (-mx.top().second < i || m[mx.top().first])) mx.pop();

        pair<int, int> x = pq[k];
        if (-x.first > r) {
            for (int j=r; j<-x.first; j++) {
                if (!m[A[j]]) {
                    mn.push({-A[j], -j});
                    mx.push({A[j], -j});
                }
            }
            r = -x.first;
        }

        if ((int)ans.size() % 2) {
            // minimize
            pair<int, int> y = {-INT_MAX, INT_MAX};
            if (!mn.empty())
                y = mn.top();
            if (-y.first <= x.second) {
                m[-y.first]++;
                i = -y.second;
                ans.push_back(-y.first);
            } else {
                m[x.second]++;
                i = -x.first;
                ans.push_back(x.second);
                k++;
            }
        } else {
            // maximize
            pair<int, int> y = {-INT_MAX, INT_MAX};
            if (!mx.empty())
                y = mx.top();
            if (y.first >= x.second) {
                m[y.first]++;
                i = -y.second;
                ans.push_back(y.first);
            } else {
                m[x.second]++;
                i = -x.first;
                ans.push_back(x.second);
                k++;
            }
        }
    }

    cout << (int)ans.size() << endl;
    for (int i=0; i<(int)ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
