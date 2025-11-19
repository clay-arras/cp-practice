// https://leetcode.com/problems/maximum-star-sum-of-a-graph

class Solution {
public:
    const static int MX = 1e5+1;
    vector<pair<int, int>> adj_list[MX];
    vector<int> arr;
    vector<bool> visited;
    int N, K;
    int ans = -INT_MAX;

    void dfs(int s) {
        visited[s] = true;

        int prev = arr[s];
        ans = max(ans, prev);
        for (int i=0; i<(int)adj_list[s].size(); i++) {
            auto p = adj_list[s][i];
            if (i < K) prev += p.first;
            ans = max(ans, prev);
            if (!visited[p.second]) 
                dfs(p.second);
        }
    }

    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        arr = vals;
        N = (int)arr.size();
        K = k;

        for (auto i : edges) {
            adj_list[i[0]].push_back({arr[i[1]], i[1]});
            adj_list[i[1]].push_back({arr[i[0]], i[0]});
        }
        for (int i=0; i<N; i++)
            sort(adj_list[i].rbegin(), adj_list[i].rend());
        
        visited = vector<bool>(N, false);
        for (int i=0; i<N; i++)
            if (!visited[i])
                dfs(i);
        return ans;
    }
};