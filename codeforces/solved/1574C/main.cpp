#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debugFunc.h"
#else
#endif

template<class T>
T firstTrue(T l, T r, function<bool(T)> f) {
    r++;
    while (l < r) {
        T mid = l + (r - l) / 2;
        if (f(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

void solve() {
    long long N; cin >> N;
    vector<long long> A(N);
    for (long long& i : A)
        cin >> i;

    long long tot = 0;
    for (long long i : A)
        tot += i;

    sort(A.begin(), A.end());
    A.erase( unique( A.begin(), A.end() ), A.end() );
    N = (int)A.size();

    long long M; cin >> M;
    while (M--) {
        long long x, y; cin >> x >> y;

        function<long long(long long)> calc = [&](long long i) {
            return max(0LL, x - A[i]) + max(0LL, y - (tot - A[i]));
        };
        function<bool(long long)> ok = [&](long long i) -> bool {
            long long k1 = max(0LL, x - A[i]) + max(0LL, y - (tot - A[i]));
            long long k2 = max(0LL, x - A[i+1]) + max(0LL, y - (tot - A[i+1]));
            if (i+1 >= N)
                k2 = LLONG_MAX;
            return k1 < k2;
        };
        long long val = firstTrue(0LL, N*1LL, ok);
        long long ans = max(0LL, x - A[val]) + max(0LL, y - (tot - A[val]));
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

/*
Lessons: make sure when you're doing binary search that you're ALWAYS checking the search space
*/
