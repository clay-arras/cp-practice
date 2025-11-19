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
    string s; cin >> s;

    int zs = 0, on = 0;
    int consZ = 0, consO = 0;
    for (int i=0; i<N-1; i++) {
        if (s[i] == '0') {
            cout << (on ? i+1-consZ : 1) << " ";
            consZ++;
            consO = 0;
        } else {
            cout << (zs ? i+1-consO : 1) << " ";
            consO++;
            consZ = 0;
        }

        if (s[i] == '0')
            zs++;
        on = i-zs+1;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

// Order matters
// 9
// 2 can't win
// 1 2 3 4 5 6 7 8 9
// 2 9
// 2: 1 < 3 4 5 6 7 8 9
//
// Solution: constructive algorithms    dp    greedy
//
// Case 1
// 1 big :: 1 less
// Ans = n-1
// PROOF:
// - Use the biggest one
// - Take all numbers except the winner and narrow them down
// - The final number is strictly less than the big one, so the big one wins
// - Then the winner is less than the big one, so it wins
// - Ditto with the 1 less :: 1 big
//
// Case 2
// x-1 less :: 1 less
// Ans: 1
// PROOF:
// - All the ones have to lose
// - 1 can't lose so no one else can win
// - Ditto with x-1 big :: 1 big
//
// ---
//
// 4
// 001
//
// 2 3 4 = Number of people
// For each battle, count the number of wins and loses
// - Use a prefix sum
//
// 2: 1 2
// 1 loss
// 1 x2
//
// 3: 1 2 3
// 1 loss :: 1 loss
// 1 x2 x3
//
// 4: 1 2 3 4
// x1 2 3 4
// 2 losses :: 1 win
// If there is 1 win, then we can pair everyone against the lowest value, since they can never win
// That way all the other losses are accounted for
//
// The last environment has to be relevant to the winner
// Every other thing can be in any order
//
// 4
// 101
//
// 2: 1 2
// x1 2
// 1 win
//
// 3: 1 2 3
// 1 big :: 1 less
// 1 2 x3
// 3 can't win
// 3 > 1
// 2 < 3
// 1 2
// 1 big
//
//
// 4: 1 2 3 4
// 1 big, 1 less :: 1 big
// 1 can't win
//
// Binary search on the range...
// Assume each value only battles twice maximum
//
// a_1 > a_2
// a_3 < a_1
// a_4 (win) > a_3
//
// It does matter which matches go
//
// 6
// 11001
//
// 1 2
// 2 wins
//
// 1 2 3
// 3 wins
//
// 1 2 3 4
// 4 can't win
// 1 2 3
// 1 2 3 wins => feed everything to 4
//
// 1 2 3 4 5
// 5 can't win
// 00 11
// 1 2 3 4 can win
//
// 1 2 3 4 6
// 11 00 1
// 1 can't win
