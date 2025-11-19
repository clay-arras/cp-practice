// https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations

class Solution {
public:
    int charDist(char a, char b) {
        if (a > b) swap(a, b);
        return min(b - a, a + 26 - b);
    }

    const static int mxV = 201;
    int memo[mxV][mxV][mxV];

    string str;
    int dp(int l, int r, int k) {
        if (r - l == 0)
            return 1;
        if (r - l < 0)
            return 0;
        if (memo[l][r][k] != -1)
            return memo[l][r][k];

        int t = 0;
        if (k >= charDist(str[l], str[r])) 
            t = max(t, 2 + dp(l+1, r-1, k - charDist(str[l], str[r])));
        t = max(t, dp(l+1, r, k));
        t = max(t, dp(l, r-1, k));

        return memo[l][r][k] = t;
    }

    int longestPalindromicSubsequence(string s, int k) {
        str = s;
        fill(&memo[0][0][0], &memo[0][0][0]+sizeof(memo)/sizeof(int), -1);
        return dp(0, (int)s.size()-1, k);
    }
};