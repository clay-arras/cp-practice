// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

class Solution {
public:
    static const int MX = 1e3+9;
    int dp[MX][MX];
    int lenLongestFibSubseq(vector<int>& arr) {
        int N = (int)arr.size();
        unordered_map<long long, int> vmap;
        for (int i=0; i<N; i++)
            vmap[arr[i]] = i+1;

        dp[0][1] = 2;
        int ans = 0;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                dp[i][j] = max(dp[i][j], 2);
                ans = max(ans, dp[i][j]);
                int vld = vmap[arr[i] + arr[j]];
                if (vld) dp[j][vld-1] = max(dp[j][vld-1], dp[i][j] + 1);
            }
        }

        return (ans == 2 ? 0 : ans);
    }
};