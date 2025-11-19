// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int N = (int)grid.size(), M = (int)grid[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        const int MXV = INT_MAX;
        queue<pair<int, int>> q;
        vector<vector<int>> dist(N, vector<int>(M, MXV));

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> s = q.front();
            q.pop();

            for (int i=0; i<4; i++) {
                int x = s.first + dx[i];
                int y = s.second + dy[i];

                if (x >= 0 && x < N && y >= 0 && y < M && grid[x][y] != 0 && dist[x][y] == MXV) {
                    dist[x][y] = dist[s.first][s.second] + 1;
                    q.push({x, y});
                }
            }
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++)
                cout << setw(3) << (dist[i][j] == MXV ? -1 : dist[i][j]) << " ";
            cout << endl;
        }

        int ans = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j] == 1)
                    ans = max(ans, dist[i][j]);
            }
        }
        return (ans == MXV ? -1 : ans);
    }
};