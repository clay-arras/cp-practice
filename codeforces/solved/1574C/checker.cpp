#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debugFunc.h"
#else
#endif

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    int tot = 0;
    for (int i : A)
        tot += i;

    sort(A.begin(), A.end());
    A.erase( unique( A.begin(), A.end() ), A.end() );
    N = (int)A.size();

    int M; cin >> M;
    while (M--) {
        int x, y; cin >> x >> y;

        function<int(int)> calc = [&](int i) {
            return max(0, x - A[i]) + max(0, y - (tot - A[i]));
        };
        int ans = INT_MAX;
        for (int i=0; i<N; i++) {
            if (calc(i) <= ans) {
                ans = calc(i);
            }
        }

        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
}
