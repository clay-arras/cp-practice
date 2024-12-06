#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const long long MX = 1e18+232;
void solve() {
    long long N, M; cin >> N >> M;
    vector<long long> F, S;

    for (int i=0; i<N; i++) {
        long long f, s; cin >> f >> s;
        F.push_back(f);
        S.push_back(s);
    }

    multiset<long long> s;
    long long sum=0, ans=MX;
    for (int l=0, r=-1; l<N and r<N; l++) {
        while (sum < M and r < N) {
            s.insert(-S[++r]);
            sum += F[r];
        }
        if (sum >= M)
            ans = min(ans, -(*s.begin()));

        s.erase(s.find(-S[l]));
        sum -= F[l];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

