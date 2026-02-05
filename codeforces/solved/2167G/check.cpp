#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

vector<vector<long long>> memo;
vector<int> A, C, cA;
int N;
 
long long dp(int i, int val) {
    if (memo[i][val] != -1)
        return memo[i][val];
    if (i == 0) return 0;

    long long ans = 1e17;
    if (cA[i-1] <= val)
        ans = min(ans, dp(i-1, cA[i-1]));
    ans = min(ans, dp(i-1, val) + C[i-1]);

    return memo[i][val] = ans;
}

void solve() {
    cin >> N;

    A = vector<int>(N), C = vector<int>(N);
    for (int& i : A)
        cin >> i;
    for (int& i : C)
        cin >> i;

    int M = 0;
    unordered_map<long long, int> cc;
    vector<int> Apr(A.begin(), A.end());
    sort(Apr.begin(), Apr.end());

    for (int i=0; i<N; i++) {
        if (cc.count(Apr[i]))
            continue;
        cc[Apr[i]] = M++;
    }
    cA = vector<int>(N);
    for (int i=0; i<N; i++)
        cA[i] = cc[A[i]];

    memo = vector<vector<long long>> (N+1, vector<long long> (M+1, -1));
    cout << dp(N, M) << endl;
    memo.clear();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
