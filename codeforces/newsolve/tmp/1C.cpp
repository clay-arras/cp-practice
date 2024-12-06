#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N, S1, S2; cin >> N >> S1 >> S2;

    vector<pair<int, int>> R;
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        R.push_back({t, i+1});
    }
    sort(R.begin(), R.end());

    vector<pair<int, int>> V;
    for (int i=1; i<=N; i++)
        V.push_back({S1*i, 1});
    for (int i=1; i<=N; i++)
        V.push_back({S2*i, 2});
    sort(V.begin(), V.end());

    vector<int> A, B;
    for (int i=0; i<N; i++) {
        if (V[i].second == 1)
            A.push_back(R[i].second);
        if (V[i].second == 2)
            B.push_back(R[i].second);
    }

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    cout << (int)A.size() << " ";
    for (int i : A)
        cout << i << " ";
    cout << endl;
    cout << (int)B.size() << " ";
    for (int i : B)
        cout << i << " ";
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
