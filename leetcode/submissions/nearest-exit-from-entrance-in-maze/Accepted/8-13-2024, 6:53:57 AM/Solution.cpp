// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int N = (int)maze.size(), M = (int)maze[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        const int MXV = INT_MAX;
        queue<pair<int, int>> q;
        vector<vector<int>> dist(N, vector<int>(M, MXV));

        dist[entrance[0]][entrance[1]] = 0;
        q.push({entrance[0], entrance[1]});
        while (!q.empty()) {
            pair<int, int> s = q.front();
            q.pop();

            for (int i=0; i<4; i++) {
                int x = s.first + dx[i];
                int y = s.second + dy[i];

                if (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == '.' && dist[x][y] == MXV) {
                    dist[x][y] = dist[s.first][s.second] + 1;
                    q.push({x, y});
                }
            }
        }

        int ans = MXV;
        for (int i=0; i<N; i++) {
            if (entrance[0] != i || entrance[1] != 0) 
                ans = min(ans, dist[i][0]);
            if (entrance[0] != i || entrance[1] != M-1) 
                ans = min(ans, dist[i][M-1]);
        }
        for (int j=0; j<M; j++) {
            if (entrance[0] != 0 || entrance[1] != j) 
                ans = min(ans, dist[0][j]);
            if (entrance[0] != N-1 || entrance[1] != j) 
                ans = min(ans, dist[N-1][j]);
        }
        return (ans == MXV ? -1 : ans);
    }
};

// [["+","+",".","+"],
//  [".",".",".","+"],
//  ["+","+","+","."]]
