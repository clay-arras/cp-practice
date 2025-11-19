// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    const static int MAXN = 1e2 + 3;
    int dp[MAXN][MAXN][2];

    int rob(vector<int>& nums) {
        deque<int> mn(nums.begin(), nums.end());

        int N = (int)nums.size();
        if (N == 1)
            return nums[0];

        int ans = 0;
        for (int s=0; s<N; s++) {
            dp[s][0][0] = mn.at(0);
            dp[s][1][0] = max(mn.at(0), mn.at(1));
            for (int i=2; i<N-1; i++) {
                dp[s][i][0] = max(dp[s][i-1][0], dp[s][i-2][0] + mn.at(i));
            }

            dp[s][N-1][1] = mn.at(N-1);
            dp[s][N-2][1] = max(mn.at(N-1), mn.at(N-2));
            for (int i=N-3; i>=1; i--) {
                dp[s][i][1] = max(dp[s][i+1][1], dp[s][i+2][1] + mn.at(i));
            }

            ans = max(ans, max(dp[s][N-2][0], dp[s][1][1]));

            int tmp = mn.back();
            mn.pop_back();
            mn.push_front(tmp);
        }
        return ans;
    }
};