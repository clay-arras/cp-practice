// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int numIslands(vector<vector<char>>& grid) {
        int N = (int)grid.size();
        int M = (int)grid[0].size();

        vector<vector<bool>> visited =
            vector<vector<bool>>(N, vector<bool>(M, false));

        function<void(int, int)> flood =
            [&](int i, int j) {
                visited[i][j] = true;
                for (int k = 0; k < 4; k++) {
                    int in = i + dx[k];
                    int jn = j + dy[k];
                    if (in >= 0 && in < N && jn >= 0 && jn < M &&
                        grid[in][jn] == '1' && !visited[in][jn]) {
                        flood(in, jn);
                    }
                }
            };

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    flood(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};