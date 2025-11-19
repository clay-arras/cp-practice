// https://leetcode.com/problems/count-number-of-possible-root-nodes

class Solution {
public:
    struct PairHash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ (h2 << 1); 
        }
    };

    const static int MXN = 1e5+1;
    unordered_map<pair<int, int>, int, PairHash> proc;
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
                int sum = 0;
                sum += proc.count({x.first, s});
                sum -= proc.count({s, x.first});
                dp(x.first, prev + sum);
            }
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        K = k;

        for (auto g : guesses) {
            adj_list[g[0]].push_back({g[1], 1}); // maybe reverse this???
            proc[{g[0], g[1]}] = 1;
        }
        for (auto g : edges) {
            if (!proc.count({g[0], g[1]}))
                adj_list[g[0]].push_back({g[1], 0});
            if (!proc.count({g[1], g[0]}))
                adj_list[g[1]].push_back({g[0], 0});
        }

        int N = (int)edges.size() + 1;
        visited = vector<bool> (N, false);

        dfs(0);
        ans += (cnt >= k);

        visited = vector<bool> (N, false);
        visited[0] = true;
        dp(0, cnt);
        
        return ans;
    }
};