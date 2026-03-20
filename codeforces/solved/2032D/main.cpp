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

    deque<int> dq = {1};
    vector<int> ans(N, -1);
    unordered_map<int, int> last;

    int i;
    ans[0] = 0;
    ans[1] = 0;
    for (i=2; i<N; i++) {
        cout << "? 1 " << i << endl;
        bool q; cin >> q;

        ans[i] = !q;
        if (!q) {
            last[!q] = i;
            dq.push_back(dq.front());
            dq.pop_front();
            break;
        }
        dq.push_back(i);
        last[i] = i;
    }

    for (i=i+1; i<N; i++) {
        cout << "? " << dq.front() << " " << i << endl;
        bool q; cin >> q;
        while (q) {
            dq.pop_front();
            cout << "? " << dq.front() << " " << i << endl;
            cin >> q;
        }

        ans[i] = last[dq.front()];
        last[dq.front()] = i;
        dq.push_back(dq.front());
        dq.pop_front();
    }

    cout << "! ";
    for (int i=1; i<N; i++)
        cout << ans[i] << " ";
    cout << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
