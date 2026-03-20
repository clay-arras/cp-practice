#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const double PI = 3.14159265358979323846264338;
struct chash {
	const uint64_t C = uint64_t(2e18 * PI) + 71;
	const uint32_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
	size_t operator()(uint64_t x) const {
		return __builtin_bswap64((x ^ RANDOM) * C);
	}
};

long long solve_odd(int K, vector<int>& A) {
    int N = (int)A.size();

    long long MX = 1e14;
    vector<array<long long, 2>> dp(N+1, {MX, MX});
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i=1; i<=N; i++) {
        if (i-1 >= 0)
            dp[i][1] = min(dp[i][1], dp[i-1][0]);
        if (i-2 >= 0) {
            dp[i][1] = min(dp[i][1], dp[i-2][1] + (A[i-1] - A[i-2])/K);
            dp[i][0] = min(dp[i][0], dp[i-2][0] + (A[i-1] - A[i-2])/K);
        }
    }
    return dp[N][1];
}

long long solve_even(int K, vector<int>& A) {
    long long ret = 0;
    for (int i=0; i<(int)A.size(); i+=2) 
        ret += (A[i+1] - A[i]) / K;
    return ret;
}

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    unordered_map<int, vector<int>, chash> m;
    for (int i=0; i<N; i++) 
        m[A[i] % K].push_back(A[i]);
    for (auto& [k, v] : m)
        sort(v.begin(), v.end());

    long long ans = 0, odds = 0;
    for (auto& [k, v] : m) {
        odds += ((int)v.size() % 2);
        if (odds > 1) {
            cout << -1 << endl;
            return;
        }
        if ((int)v.size() % 2 == 0) {
            ans += solve_even(K, v);
        } else {
            ans += solve_odd(K, v);
        }
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
