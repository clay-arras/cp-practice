#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

template<class T>
T lastTrue(T l, T r, function<bool(T)> f) {
    l--;
    for (T diff=r-l; diff>0; diff/=2)
        while (l + diff <= r && f(l + diff))
            l += diff;
    return l;
}

void solve() {
    long long N, K, X; cin >> N >> K >> X;
    vector<long long> A(N);
    for (long long& i : A)
        cin >> i;
    A.push_back(-1);
    A.push_back(X+1);
    sort(A.begin(), A.end());
    
    auto ok = [&](long long t) -> bool {
        if (t == 0) return (X+1 >= K);

        long long ans = 0;
        for (int i=1; i<N+2; i++) {
            long long diff = A[i] - A[i-1];
            if (A[i-1] >= 0 && A[i] <= X) {
                ans += max(0LL, diff - 2*t + 1);
            } else {
                ans += max(0LL, diff - t);
            }
        }
        return (ans >= K);
    };
    
    long long t = lastTrue<long long>(0LL, 1e18, ok);

    auto con = [&](long long t) {
        int cnt = K;
        if (t == 0) {
            for (int i=0; cnt>0; i++, cnt--)
                cout << i << " ";
            cout << endl;
            return;
        }

        for (int i=1; i<N+2; i++) {
            if (A[i-1] < 0) {
                for (int j=0; cnt>0 && j<=A[i]-t; j++, cnt--) 
                    cout << j << " ";
            }
            else if (A[i] > X) {
                for (int j=A[i-1]+t; cnt>0 && j<=X; j++, cnt--) 
                    cout << j << " ";
            }
            else {
                for (int j=A[i-1]+t; cnt>0 && j<=A[i]-t; j++, cnt--) 
                    cout << j << " ";
            }
        }
        cout << endl;
        assert(cnt == 0);
    };
    con(t);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
