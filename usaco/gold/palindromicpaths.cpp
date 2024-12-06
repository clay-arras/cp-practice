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

    vector<string> g(N);
    for (string& t : g)
        cin >> t;

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

Run two for loops
We loop from the top down
After we've made N moves we stop and count the string that we formed and where we form it from
Total is 2*N-1

*/
