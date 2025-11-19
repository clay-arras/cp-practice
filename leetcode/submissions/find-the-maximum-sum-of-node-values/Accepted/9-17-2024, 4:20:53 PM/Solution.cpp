// https://leetcode.com/problems/find-the-maximum-sum-of-node-values

class Solution {
public:
    const static int MX = 2e4 + 4;
    vector<long long> adj_list[MX], arr;
    vector<int> num;
    vector<vector<long long>> dp;
    vector<bool> visited;
    int N, K;

    void dfs(int i) {
        visited[i] = true;

        dp[i][0] = num[i];
        dp[i][1] = -LLONG_MAX/3;
        for (int j : adj_list[i]) {
            if (!visited[j]) {
                vector<long long> tmp = dp[i];

                dfs(j);
                dp[i][1] = max({tmp[1] + dp[j][0], tmp[1] + dp[j][1],
                                tmp[0] + dp[j][0] + arr[i] + arr[j], 
                                tmp[0] + dp[j][1] + arr[i] - arr[j]});
                dp[i][0] = max({tmp[0] + dp[j][0], tmp[0] + dp[j][1],
                                tmp[1] + dp[j][0] - arr[i] + arr[j], 
                                tmp[1] + dp[j][1] - arr[i] - arr[j]});
            }
        }
    }

    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        num = nums;
        N = (int)nums.size(), K = k;
        for (auto i : edges) {
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        visited = vector<bool>(N, false);
        dp = vector<vector<long long>> (N, vector<long long>(2, 0));
        arr = vector<long long>(N, 0);
        for (int i=0; i<N; i++)
            arr[i] = ((nums[i]^K) - nums[i]);
        
        dfs(0);
        return max(dp[0][0], dp[0][1]);
    }
};