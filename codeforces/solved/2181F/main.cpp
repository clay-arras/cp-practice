#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int& i : A)
        cin >> i;

    int ones = 0, twos = 0;
    for (int i=0; i<N; i++) {
        ones += (A[i] == 1);
        twos += (A[i] > 1);
    }
    cout << (((twos == 0) + ones) % 2 ? "Bob" : "Alice") << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*

observations: 
- problem can be simplified to ones and twos, because a player can either take
the whole pile, or take Ai-1 of it (no point in doing three steps because it
doesn't change the parity)
- having extra ones deterministically flips the parity of the answer
- Alice has a strategy to always win if the board only consists of twos,
because she can always give Bob the same pile she just took from, allowing her
to always take first pile

*/
