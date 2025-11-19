// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph

class Solution {
public:
    vector<vector<int>> adj_list;
    vector<vector<int>> ans;
    vector<bool> visited;

    void dfs(int s) {
        visited[s] = true;

        for (auto i : adj_list[s])
            if (!visited[i])
                dfs(i);
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        adj_list = vector<vector<int>> (n, vector<int>());
        ans = vector<vector<int>> (n, vector<int>());
        visited = vector<bool> (n, false);
        for (auto i : edges) 
            adj_list[i[1]].push_back(i[0]);
        
        for (int i=0; i<n; i++) {
            fill(visited.begin(), visited.end(), false);
            dfs(i);
            for (int j=0; j<n; j++) 
                if (visited[j] && i != j)
                    ans[i].push_back(j);
        }
        
        return ans;
    }
};