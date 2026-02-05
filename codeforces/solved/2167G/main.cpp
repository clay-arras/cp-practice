#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MX = 1e18;
void solve() {
    int N; cin >> N;

    vector<int> A(N), C(N);
    for (int& i : A)
        cin >> i;
    for (int& i : C)
        cin >> i;

    int M = 0;
    unordered_map<int, int> cc;
    vector<int> Apr(A.begin(), A.end());
    sort(Apr.begin(), Apr.end());
    for (int i=0; i<N; i++) {
        if (cc.count(Apr[i]))
            continue;
        cc[Apr[i]] = M++;
    }

    vector<int> cA(N);
    for (int i=0; i<N; i++)
        cA[i] = cc[A[i]];
 
    vector<long long> dp (M+1, C[0]), pdp;
    dp[cA[0]] = 0;
    pdp = dp;
    for (int i=1; i<N; i++) {
        for (int j=0; j<=M; j++) {
            int t = C[i]*(cA[i] != j);
            long long ans = MX;
            if (pdp[cA[i-1]] != MX && cA[i-1] <= j)
                ans = min(ans, pdp[cA[i-1]] + t);
            if (pdp[j] != MX) 
                ans = min(ans, pdp[j] + t);
            dp[j] = ans;
        }
        pdp = dp;
    }

    cout << *min_element(dp.begin(), dp.end()) << endl;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
