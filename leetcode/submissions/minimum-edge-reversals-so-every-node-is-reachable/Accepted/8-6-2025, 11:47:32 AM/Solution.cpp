// https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable

class Solution {
public:
    const static int MXN = 1e5+1;
    int N;
    vector<int> memo;
    bool visited[MXN];
    vector<pair<int, int>> adj_list[MXN];

    void dfs(int s) {
        visited[s] = true;

        for (auto [x, w] : adj_list[s]) {
            if (!visited[x]) {
                memo[0] += w;
                dfs(x);
            }
        }
    }

    void dp(int idx, int prev, int w) { // more of search then dp
        visited[idx] = true;
        if (idx) memo[idx] = (w ? -1 : 1) + memo[prev]; // if not base case

        for (auto [x, fw] : adj_list[idx]) {
            if (!visited[x]) {
                dp(x, idx, fw);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // easy O(N^2) solution: 
        // create adj_list where if edge is exists in that direction, then weight=0 else 1
        // loop through and add all weights using dfs

        // exists subproblems: just use DP to memoize
        // O(N)

        N = n;
        for (auto edge : edges) {
            adj_list[edge[0]].push_back({edge[1], 0});
            adj_list[edge[1]].push_back({edge[0], 1});
        }
        memo = vector<int> (N, -1);
        memo[0] = 0;
        dfs(0);

        fill(visited, visited+N, false);
        dp(0, -1, -1);

        return memo;
    }
};