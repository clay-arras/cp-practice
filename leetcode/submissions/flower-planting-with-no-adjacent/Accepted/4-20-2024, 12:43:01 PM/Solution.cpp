// https://leetcode.com/problems/flower-planting-with-no-adjacent

class Solution {
public:
    const static int MAXN = 1e4+4;
    vector<int> adj_list[MAXN];
    vector<int> visited;

    void dfs(int s) {
        if (visited[s] != -1) return;
        for (int j=1; j<=4; j++) {
            bool good = true;
            for (int i : adj_list[s]) 
                good &= (visited[i] != j || visited[i] == -1);
            if (good) visited[s] = j;
        }

        for (int i : adj_list[s]) {
            dfs(i);
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        visited = vector<int> (n, -1);

        for (auto e : paths) {
            adj_list[e[0]-1].push_back(e[1]-1);
            adj_list[e[1]-1].push_back(e[0]-1);
        }

        for (int i=0; i<n; i++)
            if (visited[i] == -1)
                dfs(i);

        return visited;
    }
};