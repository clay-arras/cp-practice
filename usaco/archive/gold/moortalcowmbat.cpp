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

// Subproblems:
// Minimum distance from i to j => graph problem
// Which letters to change and minDays => DP problem
//
// First subproblem:
// All letters are nodes
// Make an adjacency list with weights
// M^3 with FloydWarshall
//
// Second subproblem:
// Transition: We can either start a new string or keep going
// Keep track of current letter, just iterate through all M letters
//
// How to keep track if the string length is K... => add a new dimension N... too slow
//
// dp[i][c]
