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
    long long sum1 = 0, sum2 = 0;

    vector<long long> A(N);
    for (long long& t : A)
        cin >> t;

    vector<long long> s1, s2;
    bool isLast = (A[N-1] > 0);
    for (int i=0; i<N; i++) {
        if (A[i] < 0) {
            s2.push_back(-A[i]);
            sum2 += -A[i];
        } else {
            s1.push_back(A[i]);
            sum1 += A[i];
        }
    }

    if (sum1 == sum2) {
        if (s1 == s2) {
            cout << (isLast ? "first" : "second") << endl;
            return;
        }
        cout << (lexicographical_compare(s2.begin(), s2.end(),
                    s1.begin(), s1.end()) ? "first" : "second") << endl;
        return;
    }
    cout << (sum1 > sum2 ? "first" : "second") << endl;
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
