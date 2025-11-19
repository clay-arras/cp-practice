// https://leetcode.com/problems/find-the-maximum-sum-of-node-values

class Solution {
public:
    const static int MX = 2e4 + 4;
    vector<int> adj_list[MX], arr;
    vector<bool> visited;
    int N, K;
    vector<vector<int>> dp;
    vector<int> order;

    void topological(int s) {
        visited[s] = true;
        for (int i : adj_list[s]) {
            if (!visited[i])
                topological(i);
        }
        order.push_back(s);
    }

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        arr = nums;
        N = (int)arr.size(), K = k;
        for (auto i : edges) {
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        visited = vector<bool> (N, false);

        order.clear();
        topological(0);
        reverse(order.begin(), order.end());

        dp = vector<vector<int>> (N, vector<int>(2, 0));
        visited = vector<bool> (N, false);
        dp[0][0] = arr[0];

        for (int j=0; j<N; j++) {
            int s = order[j];
            int sp = (j ? order[j-1] : 0);
            visited[s] = true;
            // dp[s][0] = max(dp[s][0], arr[s] + max(dp[i][0], dp[i][1]));
            // dp[s][1] = max(dp[s][1], (arr[s]^K) + max(dp[i][0] + arr[i]^K - arr[i], dp[i][1] - arr[i]^K + arr[i]));
            // dp[s][0] = max(dp[s][0], arr[s] + max(dp[sp][0], dp[sp][1]));
            // dp[s][1] = max(dp[s][1], (arr[s]^K) + max(dp[sp][0] + arr[i]^K - arr[i], dp[sp][1] - arr[i]^K + arr[i]));
            
            for (int i : adj_list[s]) {
            //     // if (!visited[i]) {
            //     //     dp[i][0] = max(dp[i][0], arr[i] + max(dp[s][0], dp[s][1]));
            //     //     dp[i][1] = max(dp[i][1], (arr[i]^K) + max(dp[s][0] + arr[s]^K - arr[s], dp[s][1] - arr[s]^K + arr[s]));
            //     // }
                cout << s << " " << sp << " " << i << endl;
                // cout 
                if (visited[i]) {
                    dp[s][0] = max(dp[s][0], arr[s] + max(dp[sp][0], dp[sp][1]));
                    dp[s][1] = max(dp[s][1], (arr[s]^K) + max(dp[sp][0] + (arr[i]^K) - arr[i], dp[sp][1] - (arr[i]^K) + arr[i]));
                }
            }
        }

        for (int j=0; j<2; j++) {
            for (int i=0; i<N; i++)
                cout << dp[order[i]][j] << " ";
            cout << endl;
        }

        return max(dp[order[N-1]][0], dp[order[N-1]][1]);
    }
};