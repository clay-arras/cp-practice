// https://leetcode.com/problems/count-number-of-possible-root-nodes

class Solution {
public:
    const static int MXN = 1e5+1;
    unordered_map<string, int> proc;
    vector<pair<int, int>> adj_list[MXN];
    vector<bool> visited;

    int cnt = 0, ans = 0;
    int K;
    void dfs(int s) {
        visited[s] = true; 
        for (auto x : adj_list[s]) {
            if (!visited[x.first]) {
                dfs(x.first);
                cnt += x.second;
            }
        }
    }

    void dp(int s, int prev) {
        visited[s] = true; 
        if (s) ans += (prev >= K);

        for (auto x : adj_list[s]) {
            if (!visited[x.first]) {
                dp(x.first, prev + (proc[to_string(x.first) + "#" + to_string(s)] - 
                                    proc[to_string(s) + "#" + to_string(x.first)]));
            }
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        // for all N, check if at least k nodes form the special tree
        // has an easy N * guesses solution, just loop through 
        // insted of looping through N sequentially, traverse the tree. do dfs to find                             
        // if in one way then 1 point, else 0
        // if no guess edge then 0
        // dfs on ONE then use RELATIVE numbering
        K = k;

        for (auto g : guesses) {
            adj_list[g[0]].push_back({g[1], 1}); // maybe reverse this???
            proc[to_string(g[0]) + "#" + to_string(g[1])] = 1;
        }
        for (auto g : edges) {
            if (!proc.count(to_string(g[0]) + "#" + to_string(g[1])))
                adj_list[g[0]].push_back({g[1], 0});
            if (!proc.count(to_string(g[1]) + "#" + to_string(g[0])))
                adj_list[g[1]].push_back({g[0], 0});
        }

        int N = (int)edges.size() + 1;
        visited = vector<bool> (N, false);

        dfs(0);
        ans += (cnt >= k);

        visited = vector<bool> (N, false);
        visited[0] = true;
        cout << cnt << endl;
        dp(0, cnt);
        
        return ans;
    }
};