// https://leetcode.com/problems/shortest-cycle-in-a-graph

class Solution {
public:
    const static int MAXN = 1e3+1;
    int N, minDist;
    vector<int> adj_list[MAXN];

    void bfs(int src) {
        queue<int> q;
        vector<pair<int, int>> dist(N, {INT_MAX, INT_MAX});
    
        dist[src] = {0, -1};
        q.push(src);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int t : adj_list[x]) {
                if (dist[t].first == INT_MAX) {
                    dist[t].first = dist[x].first + 1;
                    dist[t].second = x;
                    q.push(t);
                } else if (dist[x].second != t) {
                    minDist = min(minDist, dist[t].first + dist[x].first + 1);
                }
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        N = n, minDist = INT_MAX;
        for (auto i : edges) {
            adj_list[i[0]].push_back(i[1]);
            adj_list[i[1]].push_back(i[0]);
        }
        
        for (int i=0; i<N; i++) 
            bfs(i);

        return minDist == INT_MAX ? -1 : minDist;
    }
};