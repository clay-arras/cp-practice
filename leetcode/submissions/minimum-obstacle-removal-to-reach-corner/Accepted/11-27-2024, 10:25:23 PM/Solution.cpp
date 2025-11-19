// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner

class Solution {
public:
    const static int MX = 1e5 + 1;
    int N, M;
    vector<vector<vector<pair<pair<int, int>, int>>>> adj_list;

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int Dijkstras() {
        vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
        priority_queue<pair<int, pair<int, int>>> q;

        dist[0][0] = 0;
        q.push({0, {0, 0}});
        while ((int)q.size()) {
            auto x = -q.top().first;
            auto u = q.top().second;
            q.pop();
            if (x != dist[u.first][u.second])
                continue;
            for (auto i : adj_list[u.first][u.second]) {
                if (x + i.second < dist[i.first.first][i.first.second]) {
                    dist[i.first.first][i.first.second] = x + i.second;
                    q.push({-dist[i.first.first][i.first.second], i.first});
                }
            }
        }
        return dist[N - 1][M - 1];
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        N = (int)grid.size(), M = (int)grid[0].size();
        adj_list = vector<vector<vector<pair<pair<int, int>, int>>>>(
            N, vector<vector<pair<pair<int, int>, int>>>(
                   M, vector<pair<pair<int, int>, int>>()));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x < N && x >= 0 && y < M && y >= 0)
                        adj_list[i][j].push_back({{x, y}, grid[x][y]});
                }
            }
        }
        return Dijkstras();
    }
};