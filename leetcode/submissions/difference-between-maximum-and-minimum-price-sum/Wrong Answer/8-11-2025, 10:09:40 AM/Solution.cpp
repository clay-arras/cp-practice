// https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum

class Solution {
public:
    const static int MX = 1e5+5;
    int N;
    vector<int> adj_list[MX];
    vector<int> p;
    vector<bool> vis;
    vector<int> state;
    vector<pair<int, int>> memo; // cost of path, diameter node
    unordered_map<int, int> diam; // cost from node to root of diam

    pair<int, int> furth; // dist, node
    void dfs1(int s, int dist) {
        vis[s] = true;
        furth = max(furth, {dist, s});
        for (int i : adj_list[s]) {
            if (!vis[i])
                dfs1(i, dist+p[i]);
        }
    }

    bool dfs2(int s, int dist, int ed) {
        vis[s] = true;
        bool ok = (s == ed);
        for (int i : adj_list[s]) {
            if (!vis[i])
                ok |= dfs2(i, dist + p[i], ed);
        }
        if (ok) diam[s] = dist;
        return ok;
    }

    pair<int, int> dp(int s) {
        if (state[s] == 2)
            return memo[s];
        if (state[s] == 1)
            return {1e9, -1};
        if (diam.count(s))
            return memo[s] = {0, s};
        
        state[s] = 1;

        pair<int, int> curr = {1e9, -1};
        for (int i : adj_list[s]) {
            auto tmp = dp(i);
            curr = min(curr, {tmp.first + p[s], tmp.second});
        }
        state[s] = 2;
        if (curr == pair<int, int>{1e9, -1})
            state[s] = 0;
        return memo[s] = curr;
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        N = n;
        p = price;
        for (auto e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        vis = vector<bool>(n, false);
        furth = {-1, -1};
        dfs1(0, p[0]);
        int st = furth.second;

        vis = vector<bool>(n, false);
        furth = {-1, -1};
        dfs1(st, p[st]);
        int ed = furth.second;

        vis = vector<bool>(n, false);
        dfs2(st, p[st], ed);

        memo = vector<pair<int, int>>(n, {1e9, -1});
        state = vector<int> (n, 0);
        for (int i=0; i<N; i++)
            dp(i);

        int ans = 0;
        for (int i=0; i<N; i++) {
            int sum = memo[i].first;
            assert(diam.count(memo[i].second));
            int l = diam[memo[i].second];
            int r = diam[ed] - diam[memo[i].second] + p[i];
            ans = max(ans, max(l, r) - p[i]);
        }
        return ans;
    }
    /*
        dp where dp[i] is the highest price path starting at root node i
        how to do transitions? 

        slip 1: assume that we are rooting at any N (O(N))
        need to search in O(logN) or preprocess
        arr [i] containing the highest price paths starting at root node i

        assertion: if path from a -> b is longest for root node a, is it longest for root node b? ; FALSE
        assertion: the highest cost path is ALWAYS on the diameter of the tree ; TT

        an array that has the distance of any point on the diameter to the root of the diameter ; to calculate diameter contribution
        an array that is the distance from the root node to the nearest path on diameter, and which node it is ; CAN DP over this
        set of all nodes inside the path. if already on the path then 0. 
        
        finally loop over any N 
        assertion: the highest cost path always ENDS on the diameter of the tree ; TRUE
    */
};