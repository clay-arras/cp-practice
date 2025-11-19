// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

class Solution {
public:
    const static int MOD = 1e9+7;
    const static int MX = 201;
    vector<pair<int, int>> adj_list[MX];

    template<class T>
    vector<T> Dijkstras(T src, int N) {
        const T mxV = 1e9+9;
        priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> q;
        vector<T> dist(N, mxV);
        dist[src] = 0;
        q.push({0, src});
        while (!q.empty()) {
            T x=q.top().first, u=q.top().second;
            q.pop();
            if (x > dist[u]) continue;
            for (auto t : adj_list[u]) {
                if (x+t.second < dist[t.first]) {
                    dist[t.first] = x+t.second;
                    q.push({dist[t.first], t.first});
                }
            }
        }
        return dist;
    }

    int N;
    vector<unordered_map<int, int>> memo;
    int dp(int i, int d) {
        if (d < 0) 
            return 0;
        else if (d == 0 && i == N-1)
            return 1;

        if (memo[i].count(d))
            return memo[i][d];

        int x = 0;
        for (auto t : adj_list[i]) 
            x = (x + dp(t.first, d - t.second)) % MOD;
        return memo[i][d] = x;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        // candidates: dijkstras, search, dp???
        // assume the problem is actually what is the number of ways to travel from a to b in x distance

        // best guess: top down dp
        // state is i (position), d (distance left)
        // need to: prove why it's fast/slow

        for (auto i : roads) {
            adj_list[i[0]].push_back({i[1], i[2]});
            adj_list[i[1]].push_back({i[0], i[2]});
        }
        int minDist = Dijkstras<int> (0, n)[n-1];
        memo.resize(n);
        N = n;

        return dp(0, minDist);
    }
};