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
    cout << N << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*

Third condition: all elements are prime
Naive solution: NQ time, just iterate through the subsequence and add a value every time we run into something that isn't relatively prime
Question: how to process the range without going through it naively

Idea: use bitsets to do the problem and represent the primes...

4
3
8 1 2
4
6 9 4 2
9
1 2 3 4 5 6 7 8 9
3

3
8
1

*/
