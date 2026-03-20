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
    vector<int> A(N), B(N);
    for (int& i : A)
        cin >> i;
    for (int& i : B)
        cin >> i;

    bool dups = false;
    unordered_map<int, int> cnt;
    for (int i : A) {
        if (cnt[i])
            dups = true;
        cnt[i]++;
    }
    for (int i : B)
        cnt[i]--;

    bool nok = false;
    for (auto [k, v] : cnt)
        nok |= v;

    if (nok) {
        cout << "NO" << endl;
        return;
    }
    if (dups) {
        cout << "YES" << endl;
        return;
    }

    int ans = 0;
    for (int i=0; i<N; i++) 
        ans += (A[i] != B[i]);
    cout << (ans % 2 == 1 ? "YES" : "NO") << endl;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
