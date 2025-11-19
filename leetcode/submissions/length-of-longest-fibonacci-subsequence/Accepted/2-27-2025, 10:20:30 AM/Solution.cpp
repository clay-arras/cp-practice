// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
    const uint64_t C = uint64_t(2e18 * 3.1415926535897932384612323666) + 71;
    const uint32_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    size_t operator()(uint64_t x) const { return __builtin_bswap64((x ^ RANDOM) * C); }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int N = (int)arr.size();
        vector<vector<int>> dp(N+1, vector<int> (N+1, 2));

        gp_hash_table<int, int, chash> vmap;
        // unordered_map<int, int> vmap;
        for (int i=0; i<N; i++)
            vmap[arr[i]] = i+1;

        dp[0][1] = 2;
        int ans = 0;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                ans = max(ans, dp[i][j]);
                // int vld = vmap[arr[i] + arr[j]];
                int vld = (vmap.find(arr[i] + arr[j]) != vmap.end() ? vmap[arr[i] + arr[j]] : 0);
                if (vld) dp[j][vld-1] = max(dp[j][vld-1], dp[i][j] + 1);
            }
        }

        return (ans == 2 ? 0 : ans);
    }
};