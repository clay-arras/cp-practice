// https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations

class Solution {
public:
    int charDist(char a, char b) {
        if (a > b) swap(a, b);
        return min(b - a, a + 26 - b);
    }

    string str;
    int dp(int l, int r, int k, vector<vector<vector<int>>> &memo) {
        if (r - l == 0)
            return 1;
        if (r - l < 0)
            return 0;
        if (memo[l][r][k] != -1)
            return memo[l][r][k];

        int t = 0;
        if (k >= charDist(str[l], str[r])) 
            t = max(t, 2 + dp(l+1, r-1, k - charDist(str[l], str[r]), memo));
        t = max(t, dp(l+1, r, k, memo));
        t = max(t, dp(l, r-1, k, memo));

        return memo[l][r][k] = t;
    }

    int longestPalindromicSubsequence(string s, int k) {
        str = s;
        int N = (int)s.size();
        vector<vector<vector<int>>> memo 
            (N, vector<vector<int>> (N, vector<int> (k+1, -1)));
        return dp(0, (int)s.size()-1, k, memo);
    }
};

// lessons: don't sleep on recursive dp, pattern is to use recursive dp with palindromes since overlapping subproblems