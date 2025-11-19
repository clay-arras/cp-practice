// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    const static int MAXN = 2e5 + 4;
    vector<int> adj_list[MAXN];
    // bool visited[MAXN];
    vector<bool> visited;

    int dest;
    bool ok;
    void dfs(int s) {
        if (s == dest)
            ok = true;

        if (visited[s])
            return;
        visited[s] = true;

        for (int i : adj_list[s]) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited = vector<bool> (n + 1, false);
        ok = false;
        dest = destination;

        for (auto i : edges) {
            adj_list[i[1]].push_back(i[0]);
            adj_list[i[0]].push_back(i[1]);
        }

        dfs(source);
        return ok;
    }
};