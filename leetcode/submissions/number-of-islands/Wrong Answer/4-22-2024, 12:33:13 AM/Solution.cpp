// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<vector<bool>> visited;

    int N, M;
    vector<vector<char>> g;
    void flood(int i, int j) {
        cout << i << j << endl;
        visited[i][j] = true;
        for (int x : dx) {
            for (int y : dy) {
                // int in = i + x;
                // int jn = j + y;
                if (i + x >= 0 && i + x < N && j + y >= 0 && j + y < M &&
                    g[i + x][j + y] == '1' && !visited[i + x][j + y]) {
                    flood(i + x, j + y);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        N = (int)grid.size();
        M = (int)grid[0].size();

        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        g = grid;

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && g[i][j] == '1') {
                    flood(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};