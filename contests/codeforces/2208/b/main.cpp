#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, K, P, M; cin >> N >> K >> P >> M;
    --P;

    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    priority_queue<pair<bool, int>> pq;
    deque<pair<bool, int>> dq;

    for (int i=0; i<N; i++) {
        if (i < K) {
            pq.push({i == P, -A[i]});
        } else {
            dq.push_back({i == P, -A[i]});
        }
    }

    long long cost = 0, ans = 0;
    while (cost <= M) {
        auto x = pq.top(); 
        pq.pop();
        cost += -x.second;

        if (cost > M)
            break;
        ans += x.first;

        dq.push_back(x);
        pq.push(dq.front());
        dq.pop_front();
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*
priority queue for the first K elements, deque for the last other elements
*/
