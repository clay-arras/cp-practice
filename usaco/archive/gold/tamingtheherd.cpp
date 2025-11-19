#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

const int MX = 100;
int dp[MX][MX];
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int& t : A)
        cin >> t;

    memset(&dp[0][0], MX, sizeof(dp));



    // Answer

    for (int i=1; i<=N; i++)
        cout << dp[i][N-1] << endl;
    cout << endl;

    // Debug
    cout << "   ";
    for (int i=0; i<=N; i++)
        cout << setw(10) << i << " ";
    cout << endl;

    for (int i=0; i<=N; i++) {
        cout << i << ": ";
        for (int j=0; j<=N; j++)
            cout << setw(10) << dp[i][j] << " ";
        cout << endl;
    }
}

/*

Problem: how do we find the supposed value of this number of breakout
- We run another for loop, we find the next value to put the new breakout position on
- How would that work...

Loop until the end of the array. Since we know where we put the last breakout position, we know what value it's supposed to be
Solution:
- We loop through all the values (order pending)
- We loop through all the possible next positions to put a breakout

The previous position is i is zero
dp[i][x]



*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*
Cases: if the first log isn't zero then there has to be at least one tampered

The Nth breakout occured on the ith tile
Count the number of tampered that it has
Overall O(N^3) so far

Find: base case, the transitions, variables

How many breakouts have happened total
for (int totBreak=1; totBreak<=N; totBreak++) {
    Declare DP
    Declare first breakout

    for (int currBreak=1; currBreak<totBreak; currBreak++) {
        for (int i=0; i<N; i++) {
            How do we calculate all the previous values
            We look at how far its been since the last breakout and we calculate the predicted value
            How do we calculate the predicted value

            For every stage we can either move on, in which case we add (predVal != actVal)
            Or we can set this value to the breakout, in which case we add (actVal != 0)
            And set the new breakout value

            We can run another dimension on the DP so that we have days since last breakout
            dp[k][i] = min(dp[k][i], dp[k-1][c] + (predVal != actVal));

        }
    }
}

Breaking it into seperate components didn't apply to this problem
Shouldn't have did the queries like that
Consider doing a DP so that we do the minimum amount of changes so that there are X breakouts among the first I entries

There are X breakouts in the first I entries
dp[currEntry][numBreak] is the amount of changes to the log such that there are X breakouts in the first I entries
O(N^2) to O(N^3)

Transitions:
Possible solution: add a new dimension to the array, lastBreakout

Cases:
This value is part of normal breakout
dp[i][x] = min(dp[i][x], dp[i-1][x] + (if same));

This value has a new breakout
dp[i][x] = min(dp[i][x], dp[i-1][x-1] + (if == 0));

Base case:
dp[0][0] = 0

Observation:
Assuming there are k breakouts in the first i values, what's the minimum amount of edits possible
Answer is dp[N-1][i]

for (int i=0; i<N; i++) {
    cout << dp[N-1][i] << endl;
}
cout << endl;

 */
