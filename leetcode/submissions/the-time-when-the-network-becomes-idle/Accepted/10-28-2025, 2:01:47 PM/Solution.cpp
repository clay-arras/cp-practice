// https://leetcode.com/problems/the-time-when-the-network-becomes-idle

class Solution {
public:
    vector<vector<int>> adj_list;

    vector<int> bfs(int src, int N) {
        vector<int> dist(N, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int x = q.front(); q.pop();

            for (int t : adj_list[x]) {
                if (dist[t] == -1) {
                    dist[t] = dist[x] + 1;
                    q.push(t);
                }
            }
        }
        return dist;
    }


    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // when network stops sending messages: 2*maxLen
        // last time network sends message: (2*maxLen // patience) * patience
        // when message gets back: (2*maxLen // patience) * patience + 2*maxLen

        int N = (int)patience.size();
        adj_list = vector<vector<int>> (N);

        for (auto e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        vector<int> dist = bfs(0, N);

        int ans = 0;
        for (int i=1; i<N; i++) {
            ans = max(ans, ((2*dist[i] - 1)/ patience[i]) * patience[i] + 2*dist[i] + 1);
        }
        return ans;
    }
};