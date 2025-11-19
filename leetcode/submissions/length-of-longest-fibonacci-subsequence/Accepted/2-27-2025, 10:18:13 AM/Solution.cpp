// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLen = 0;
        // dp[prev][curr] stores length of Fibonacci sequence ending at indexes
        // prev,curr
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        // Map each value to its index for O(1) lookup
        unordered_map<int, int> valToIdx;

        // Fill dp array
        for (int curr = 0; curr < arr.size(); curr++) {
            valToIdx[arr[curr]] = curr;

            for (int prev = 0; prev < curr; prev++) {
                // Find if there exists a previous number to form Fibonacci
                // sequence
                int diff = arr[curr] - arr[prev];
                int prevIdx = (valToIdx.find(diff) != valToIdx.end())
                                  ? valToIdx[diff]
                                  : -1;

                // Update dp if valid Fibonacci sequence possible
                // diff < arr[prev] ensures strictly increasing sequence
                if (diff < arr[prev] && prevIdx >= 0) {
                    dp[prev][curr] = dp[prevIdx][prev] + 1;
                } else {
                    dp[prev][curr] = 2;
                }

                maxLen = max(maxLen, dp[prev][curr]);
            }
        }

        // Return 0 if no sequence of length > 2 found
        return maxLen > 2 ? maxLen : 0;
    }
};