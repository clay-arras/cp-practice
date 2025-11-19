// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i

class Solution {
public:
    int N, M;
    vector<vector<int>> g;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int Dijkstras() {
        const int mxV = INT_MAX;
        vector<vector<int>> dist(N, vector<int>(M, mxV));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        
        dist[0][0] = 0;
        q.push({0, {0, 0}});
        
        while ((int)q.size()) {
            int x = q.top().first;
            pair<int, int> u = q.top().second;
            q.pop();
            
            for (int i=0; i<4; i++) {
                int nx = u.first + dx[i];
                int ny = u.second + dy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                
                int ndist = max(dist[u.first][u.second], g[nx][ny]) + 1;
                
                if (ndist < dist[nx][ny]) {
                    dist[nx][ny] = ndist;
                    q.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
        return dist[N-1][M-1];
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        N = (int)moveTime.size(), M = (int)moveTime[0].size();
        g = moveTime;
        return Dijkstras();
    }
};