// https://leetcode.com/problems/find-the-count-of-monotonic-pairs-ii

class Solution {
public:
    vector<int> arr;
    int N;

    int memo[2001][1001];
    const int MOD = 1e9 + 7;
    int dp(int i, int last) {
        if (i >= N)
            return 1;
        if (memo[i][last] != -1)
            return memo[i][last];

        long long sum = 0;
        for (int j = max(0, arr[i]-arr[i-1])+last; j <= arr[i]; j++) {
            sum += dp(i + 1, j) % MOD;
        }
        memo[i][last] = sum % MOD;
        return memo[i][last];
    }

    int countOfPairs(vector<int>& nums) {
        fill(&memo[0][0], &memo[0][0] + sizeof(memo) / sizeof(memo[0][0]), -1);
        arr = nums;
        N = (int)arr.size();

        long long sum = 0;
        for (int i = 0; i <= arr[0]; i++)
            sum += dp(1, i) % MOD;
        return sum % MOD;
    }
};