// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

class Solution {
public:
    const int mxV = 2e9+10;
    vector<vector<pair<int, int>>> adj_list;

    vector<int> dijkstras(int src, int N) {
        priority_queue<pair<int, int>> pq;
        vector<int> dist(N, mxV);

        dist[src] = 0;
        pq.push({-0, src});

        while (!pq.empty()) {
            int x = pq.top().second, d = -pq.top().first;
            pq.pop();

            if (d > dist[x]) continue;
            for (auto t : adj_list[x]) {
                if (d + t.second < dist[t.first]) {
                    dist[t.first] = d + t.second;
                    pq.push({-dist[t.first], t.first});
                }
            }
        }
        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        adj_list = vector<vector<pair<int, int>>> (n);
        for (auto e : edges) {
            adj_list[e[0]].push_back({e[1], e[2]});
            adj_list[e[1]].push_back({e[0], e[2]});
        }

        pair<int, int> ans = {INT_MAX, 1};
        for (int i=0; i<n; i++) {
            vector<int> arr = dijkstras(i, n);
            int cnt = 0;
            for (int j : arr)
                cnt += (j <= distanceThreshold);
            ans = min(ans, {cnt, -i});
        }

        return -ans.second;
    }
};
