#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

int longestCommonSubsequence(string text1, string text2) {
    int len1 = (int)text1.size();
    int len2 = (int)text2.size();
    vector<vector<int>> dp(len1, vector<int> (len2, 0));

    for (int i=0; i<len1; i++) {
        if (text1[i] == text2[0])
            dp[i][0] = 1;
        if (i)
            dp[i][0] = max(dp[i-1][0], dp[i][0]);
    }
    for (int i=0; i<len2; i++) {
        if (text2[i] == text1[0])
            dp[0][i] = 1;
        if (i)
            dp[0][i] = max(dp[0][i-1], dp[0][i]);
    }

    for (int i=1; i<len1; i++) {
        for (int j=1; j<len2; j++) {
            if (text1[i] == text2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[len1-1][len2-1];
}

// O(N^2) solution with maps
// Put all subsequences into a map and then loop through all subsequences in second

void solve() {
    string s1 = "ace";
    string s2 = "defacedf";

    cout << longestCommonSubsequence(s1, s2) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}
