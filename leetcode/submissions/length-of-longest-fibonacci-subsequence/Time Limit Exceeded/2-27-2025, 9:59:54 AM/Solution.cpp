// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int N = (int)arr.size();
        vector<vector<int>> dp(N+1, vector<int> (N+1, 2));

        cc_hash_table<int, int> vmap;
        // unordered_map<int, int> vmap;
        for (int i=0; i<N; i++)
            vmap[arr[i]] = i+1;

        dp[0][1] = 2;
        int ans = 0;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                ans = max(ans, dp[i][j]);
                int vld = vmap[arr[i] + arr[j]];
                if (vld) dp[j][vld-1] = max(dp[j][vld-1], dp[i][j] + 1);
            }
        }

        return (ans == 2 ? 0 : ans);
    }
};