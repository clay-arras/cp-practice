// https://leetcode.com/problems/find-the-maximum-sum-of-node-values

class Solution {
public:
    const static int MX = 2e4 + 4;
    vector<int> adj_list[MX], arr;
    vector<vector<int>> dp;
    vector<bool> visited;
    int N, K;

    void dfs(int i) {
        visited[i] = true;

        dp[i][0] = arr[i];
        for (int j : adj_list[i]) {
            if (!visited[j]) {
                vector<int> tmp = dp[i];

                dfs(j);
                dp[i][1] = max({tmp[1] + dp[j][0], tmp[1] + dp[j][1],
                                tmp[0] + dp[j][0] + ((arr[i]^K) - arr[i]) + ((arr[j]^K) - arr[j]), 
                                tmp[0] + dp[j][1] + ((arr[i]^K) - arr[i]) - ((arr[j]^K) - arr[j])});
                dp[i][0] = max({tmp[0] + dp[j][0], tmp[0] + dp[j][1],
                                tmp[1] + dp[j][0] - ((arr[i]^K) - arr[i]) + ((arr[j]^K) - arr[j]), 
                                tmp[1] + dp[j][1] - ((arr[i]^K) - arr[i]) - ((arr[j]^K) - arr[j])});
            }
        }
    }

    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        arr = nums;
        N = (int)arr.size(), K = k;
        for (auto i : edges) {
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        visited = vector<bool>(N, false);
        dp = vector<vector<int>> (N, vector<int>(2, 0));
        
        dfs(0);
        for (int j=0; j<2; j++) {
            for (int i=0; i<N; i++)
                cout << dp[i][j] << " ";
            cout << endl;
        }

        return max(dp[0][0], dp[0][1]);
    }
};