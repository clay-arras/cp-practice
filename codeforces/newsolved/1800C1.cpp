#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long N; cin >> N;

    vector<long long> S(N);
    for (long long& t : S)
        cin >> t;

    long long sum = 0;
    multiset<long long> M;
    for (long long i=0; i<N; i++) {
        if (S[i]) {
            M.insert(S[i]);
        } else {
            if ((long long)M.size()) {
                sum += *M.rbegin();
                M.erase(prev(M.end()));
            }
        }
    }
    cout << sum << endl;
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

If the next K values are zeroes, then we look into the pile and take the K biggest values
If the next K values are bonuses, then we add them into the pile

*/
