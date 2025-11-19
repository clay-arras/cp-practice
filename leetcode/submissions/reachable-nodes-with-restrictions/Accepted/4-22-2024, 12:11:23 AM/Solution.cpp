// https://leetcode.com/problems/reachable-nodes-with-restrictions

class Solution {
public:
    const static int MAXN = 1e5 + 1;
    vector<int> adj_list[MAXN];
    vector<bool> visited;
    map<int, int> m;

    int count = 0;
    void dfs(int s) {
        visited[s] = true;
        count++;

        for (int i : adj_list[s]) {
            if (!visited[i] && !m[i]) {
                dfs(i);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        visited = vector<bool>(n, false);
        for (auto e : edges) {
            adj_list[e[1]].push_back(e[0]);
            adj_list[e[0]].push_back(e[1]);
        }
        for (auto r : restricted)
            m[r]++;

        dfs(0);
        return count;
    }
};