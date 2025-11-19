// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

class Solution {
public:
    const static int MOD = 1e9+7;
    const static int MX = 201;
    vector<pair<int, long long>> adj_list[MX];

    template<class T>
    vector<T> Dijkstras(T src, int N) {
        const T mxV = 1e18+9;
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
    vector<pair<long long, long long>> memo;
    pair<int, long long> dp(int i, long long d) {
        if (d < 0)
            return {0, 0};
        if (d == 0)
            return {0, i == N-1};
        if (memo[i].first > d)
            return {0, 0};
        if (memo[i].first == d)
            return memo[i];

        long long x = 0;
        for (auto t : adj_list[i]) 
            x = (x + dp(t.first, d - t.second).second) % MOD;
        return memo[i] = {d, x};
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        for (auto i : roads) {
            adj_list[i[0]].push_back({i[1], i[2]});
            adj_list[i[1]].push_back({i[0], i[2]});
        }
        long long minDist = Dijkstras<long long> (0, n)[n-1];
        std::cout << minDist << std::endl;
        N = n;
        memo = vector<pair<long long, long long>> (n, {-1, -1});
        int ans = dp(0, minDist).second;

        return ans;
    }
};