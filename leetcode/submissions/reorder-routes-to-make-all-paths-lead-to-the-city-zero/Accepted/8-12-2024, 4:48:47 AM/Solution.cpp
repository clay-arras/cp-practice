// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    const static int MX = 5e4+1;
    int ans = 0;
    vector<pair<int, int>> adj_list[MX];
    vector<bool> visited;

    void dfs(int x) {
        visited[x] = true;
        for (pair<int, int> i : adj_list[x]) {
            if (!visited[i.first]) {
                ans += i.second;
                dfs(i.first);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        for (auto i : connections) {
            adj_list[i[0]].push_back({i[1], 1});
            adj_list[i[1]].push_back({i[0], 0});
        }
        visited = vector<bool>(n, false);
        dfs(0);
        return ans;
    }
};