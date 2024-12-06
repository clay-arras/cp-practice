#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

// 1. Make one edge at the beginning and order edges such that they are in the order that you traverse the tree
// 2. For each edge count the number of other edges that are after this one
// 3. Add up the values and that should be the answer
//
// Otherwise we can double count on purpose and scrap the ordering, then we just divide by two
