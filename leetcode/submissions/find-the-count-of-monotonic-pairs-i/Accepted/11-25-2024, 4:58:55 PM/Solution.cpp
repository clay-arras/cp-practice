// https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i

class Solution {
public:
    vector<int> arr;
    int N;

    int memo[2001][51][51];
    const int MOD = 1e9+7;
    int dp(int i, int mx, int mn) {
        if (i < 0) return 1;
        if (memo[i][mx][mn] != -1)
            return memo[i][mx][mn];

        long long sum = 0;
        for (int j=0; j<=mx; j++) {
            if (arr[i] - j >= mn) {
                sum += dp(i-1, j, arr[i] - j) % MOD;
            }
        }
        memo[i][mx][mn] = sum % MOD;
        return memo[i][mx][mn];
    }

    int countOfPairs(vector<int>& nums) {
        fill(&memo[0][0][0], &memo[0][0][0] + sizeof(memo)/sizeof(memo[0][0][0]), -1);
        arr = nums;
        N = (int)arr.size();

        return dp(N-1, 50, 0);
    }
};