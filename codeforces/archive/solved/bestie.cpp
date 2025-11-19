#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define debug(...)
#define open(x)
#endif

void solve(){
    int N; cin >> N;

    vector<int> A(N);
    for (int& t : A)
        cin >> t;

    if (N == 1) {
        cout << (A[0] == 1 ? 0 : 1) << endl;
        return;
    }
    else if (N == 2) {
        if (gcd(A[0], A[1]) == 1) {
            cout << 0 << endl;
        } else if (gcd(A[0], gcd(A[1], 2)) == 1) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
        return;
    }

    int tot = A[0];
    for (int i=0; i<N-2; i++) {
        tot = gcd(tot, A[i]);
    }

    int cost = 3;
    if (gcd(tot, gcd(A[N-1], A[N-2])) == 1)
        cost = 0;
    else if (gcd(gcd(tot, A[N-2]), gcd(A[N-1], N-1+1)) == 1)
        cost = 1;
    else if (gcd(gcd(tot, A[N-1]), gcd(A[N-2], N-2+1)) == 1)
        cost = 2;
    cout << cost << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while(t--){
        solve();
    }
}

/*

Observation:
- You can only select each index once
- Always better to start from the end

- Observation: Selecting the last two always results in a solution

 */
