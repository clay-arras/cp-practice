#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MOD = 1e9+7;
const int nMX = 1e5+5;
const int mMX = 1e2+2;
long long DP[nMX][mMX];

void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for (int& t : A)
        cin >> t;

    int prev = A[0], dist = 1;
    for (int i=1; i<N; i++) {
        if (A[i] != 0) {
            if (abs(A[i] - prev) > dist and prev != 0) {
                cout << 0 << endl;
                return;
            }
            prev = A[i];
            dist = 1;
        } else {
            dist++;
        }
    }

    if (A[0] == 0) {
        for (int i=1; i<=M; i++)
            DP[0][i] = 1;
    } else DP[0][A[0]] = 1;

    long long ans = 1;
    for (int i=1; i<N+1; i++) {
        for (int j=1; j<=M; j++) {
            DP[i][j] = DP[i-1][j]%MOD + DP[i-1][j+1]%MOD + DP[i-1][j-1]%MOD;
            DP[i][j] %= MOD;
        }
        if (A[i] != 0) {
            if (A[i-1] == 0) {
                if (DP[i][A[i]] != 0) {
                    ans *= DP[i][A[i]] % MOD;
                    ans %= MOD;
                }
            }
            for (int j=0; j<=M; j++)
                DP[i][j] = 0;
            DP[i][A[i]] = 1;
        }
    }

    long long sum = 0;
    if (A[N-1] == 0) {
        for (int i=0; i<=M; i++) {
            if (DP[N-1][i])
                sum += DP[N-1][i];
        }
    }
    if (sum != 0) {
        ans *= sum;
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*



*/
