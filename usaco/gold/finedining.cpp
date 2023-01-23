#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

// Algorithm: Run Dijkstras on the first graph.
// Then construct a new graph where the haybales are negative and run Dijkstras on it again
// Keeping an array of visited so that they aren't visited twice (infinite loop)

void solve(){
    int N, M, K; cin >> N >> M >> K;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
