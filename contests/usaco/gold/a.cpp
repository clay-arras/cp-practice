#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

void solve(){
    int N, A, B; cin >> N >> A >> B;

    vector<int> P(N), C(N), X(N);
    for (int i=0; i<N; i++){
        int p, c, x; cin >> p >> c >> x;
        P[i] = p, C[i] = c, X[i] = x;
    }

    vector<vector<vector<int>>> dp
        (N+1, vector<vector<int>> (A+1, vector<int> (B+1, 0)));

    dp[0][A][B] = 0;
    int mxV = 0;
    for (int i=0; i<N; i++){
        for (int a=A; a>=0; a--){
            for (int b=B; b>=0; b--){
                int cCost = C[i], xCost = 0;
                while (cCost > 0 and b-xCost >= 0){
                    // Do we have to iterate over A and B
                    dp[i][a-cCost][b-xCost] = max(dp[i][a-cCost][b-xCost], dp[i][a][b] + P[i]);
                    mxV = max(mxV, dp[i][a-cCost][b-xCost]);
                }

            }
        }
    }
    cout << mxV << endl;
}

// Preliminary thoughts: for each cow, we can convert the cones to money and try to solve it that way.
// There is definitely some sort of sorting involved to sort which cows are more worth it
// We want to maximize the sum of popularity
//
// Thread 1: Dynamic Programming
// We have to iterate over the cows dp[i] and decide whether we want to buy or not
// If we do want to buy, we have to decide how much money or how many cones we want to use
// Just try all of them lmao
// dp[i][m][c] is the money left, cones left, and which cow we are on
// Knapsack

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while(t--){
        solve();
    }
}
