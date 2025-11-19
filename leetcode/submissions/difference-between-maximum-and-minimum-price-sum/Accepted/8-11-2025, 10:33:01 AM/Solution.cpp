// https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum

class Solution {
public:
    const static int MX = 1e5+5;
    const static long long MXV = 1e18;
    int N;
    vector<int> adj_list[MX];
    vector<int> p;
    vector<bool> vis;
    vector<int> state;
    vector<pair<long long, int>> memo; // cost of path, diameter node
    unordered_map<int, long long> diam; // cost from node to root of diam

    pair<long long, long long> furth; // dist, node
    void dfs1(long long s, long long dist) {
        vis[s] = true;
        furth = max(furth, {dist, s});
        for (long long i : adj_list[s]) {
            if (!vis[i])
                dfs1(i, dist+p[i]);
        }
    }

    bool dfs2(long long s, long long dist, long long ed) {
        vis[s] = true;
        bool ok = (s == ed);
        for (long long i : adj_list[s]) {
            if (!vis[i])
                ok |= dfs2(i, dist + p[i], ed);
        }
        if (ok) diam[s] = dist;
        return ok;
    }

    pair<long long, long long> dp(long long s) {
        if (state[s] == 2)
            return memo[s];
        if (state[s] == 1)
            return {MXV, -1};
        if (diam.count(s))
            return memo[s] = {0, s};
        state[s] = 1;

        pair<long long, long long> curr = {MXV, -1};
        for (long long i : adj_list[s]) {
            auto tmp = dp(i);
            curr = min(curr, {tmp.first + p[s], tmp.second});
        }
        state[s] = 2;
        if (curr == pair<long long, long long>{MXV, -1})
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

        memo = vector<pair<long long, int>>(n, {MXV, -1});
        state = vector<int> (n, 0);
        for (int i=0; i<N; i++)
            dp(i);

        long long ans = 0;
        for (int i=0; i<N; i++) {
            long long sum = memo[i].first;
            assert(diam.count(memo[i].second));
            long long l = diam[memo[i].second];
            long long r = diam[ed] - diam[memo[i].second] + p[memo[i].second];
            ans = max(ans, sum + max(l, r) - p[i]);
        }
        return ans;
    }
};