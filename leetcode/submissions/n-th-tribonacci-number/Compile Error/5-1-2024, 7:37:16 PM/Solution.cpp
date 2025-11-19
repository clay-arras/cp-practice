// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    const int MAXN = 37;
    long long dp[MAXN];
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        if (dp[n] == 0) {
            dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
            return dp[n];
        }
    }
};