#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    long long A, B, N, M; cin >> A >> B >> N >> M;

    vector<int> nFence(N+1), mFence(M+1);
    for (int i=0; i<N; i++)
        cin >> nFence[i];
    for (int j=0; j<M; j++)
        cin >> mFence[j];
    sort(nFence.begin(), nFence.end());
    sort(mFence.begin(), mFence.end());

    for (int i=0; i<N; i++)
        nFence[i] = nFence[i + 1] - nFence[i];
    nFence[N] = A - nFence[N];

    for (int j=0; j<M; j++)
        mFence[j] = mFence[j + 1] - mFence[j];
    mFence[M] = B - mFence[M];

    sort(nFence.begin(), nFence.end());
    sort(mFence.begin(), mFence.end());

    long long ans = N*mFence[0] + M*nFence[0];
    for (int np=1, mp=1; np<=N and mp<=M;) {
        if (nFence[np] > mFence[mp])
            ans += mFence[mp++] * (N-np+1);
        else
            ans += nFence[np++] * (M-mp+1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);

    int t=1;
    while (t--) {
        solve();
    }
}

/*

Current time complexity with Kruskals: N^2 * logN
Time complexity with dense graphs Prim's: N^2


*/
