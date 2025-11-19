#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long N, C, D; cin >> N >> C >> D;
    int NN = N;

    map<int, int> m;
    for (int i=0; i<N; i++) {
        int t; cin >> t;
        m[t]++;
    }

    int sum = 0;
    vector<int> B;
    B.push_back(0);
    for (auto& [k, v] : m) {
        sum += v-1;
        B.push_back(k);
    }

    N = (int)B.size();
    vector<int> diff(N+1, 0);
    for (int i=1; i<=N; i++) {
        diff[i] = B[i] - B[i-1] - 1;
    }
    vector<int> pref(N+1, 0);
    pref[0] = diff[0];
    for (int i=1; i<=N; i++) {
        pref[i] = diff[i-1] + pref[i-1];
    }

    long long ans = 1e18;
    for (int i=N-1, d=0; i>=1; i--, d++) {
        ans = min(ans, pref[i+1] * D + sum * C + d * C);
    }
    ans = min(ans, C*NN + D);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*

Go through all the values from the end to the beginning
Find out how many values need to be removed (all the duplicates)
Find out how many values need to be added (all the blanks)

*/
