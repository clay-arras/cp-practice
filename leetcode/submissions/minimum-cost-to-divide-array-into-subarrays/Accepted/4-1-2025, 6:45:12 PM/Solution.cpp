// https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays

class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();
        vector<long long> prefixNums(n, 0), prefixCosts(n, 0);
        
        // Build prefix sum for nums
        prefixNums[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixNums[i] = prefixNums[i - 1] + nums[i];
        }
        
        // Build prefix sum for cost
        prefixCosts[0] = cost[0];
        for (int i = 1; i < n; i++) {
            prefixCosts[i] = prefixCosts[i - 1] + cost[i];
        }
        
        // dp[i][j] will store the minimum cost for partitioning the subarray starting at i and ending at j
        // Use -1 to indicate an uncomputed state.
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        
        long long ans = solve(0, 0, k, prefixNums, prefixCosts, dp);
        return ans;
    }
    
private:
    long long solve(int start, int end, int k,
                    const vector<long long>& prefixNums,
                    const vector<long long>& prefixCosts,
                    vector<vector<long long>>& dp) {
        int n = prefixNums.size();
        
        // Base case: if we've reached the end of the array.
        if (end == n) {
            return (start == n) ? 0 : numeric_limits<long long>::max();
        }
        
        // Return the result if already computed.
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        
        // Compute the sum of the current subarray for nums and cost.
        long long currentNumsSum = prefixNums[end];
        long long currentCostSum = prefixCosts[n - 1];  // total sum of cost
        if (start != 0) {
            currentNumsSum = prefixNums[end] - prefixNums[start - 1];
            currentCostSum = prefixCosts[n - 1] - prefixCosts[start - 1];
        }
        
        // Compute the cost for the current subarray.
        long long currentSubarrayCost = (currentNumsSum + k) * currentCostSum;
        
        // Option 1: cut the subarray here and add the cost of the next partition.
        long long costIfCutHere = currentSubarrayCost;
        long long nextCost = solve(end + 1, end + 1, k, prefixNums, prefixCosts, dp);
        if (nextCost == numeric_limits<long long>::max())
            costIfCutHere = numeric_limits<long long>::max();
        else
            costIfCutHere += nextCost;
        
        // Option 2: extend the current subarray to include the next element.
        long long costIfExtend = solve(start, end + 1, k, prefixNums, prefixCosts, dp);
        
        // Choose the option with the minimum cost.
        dp[start][end] = min(costIfCutHere, costIfExtend);
        return dp[start][end];
    }
};
