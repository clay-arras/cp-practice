// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    int N, M;
    vector<vector<int>> m;
    vector<vector<bool>> visited;
    vector<int> ans;
    vector<int> dy = {1, 0, -1, 0};
    vector<int> dx = {0, 1, 0, -1};

    void dfs(int i, int j, int it) {
        visited[i][j] = true;
        ans.push_back(m[i][j]);

        for (int k=0; k<4; k++) {
            int t = (k+it)%4;
            int x = i+dx[t], y = j+dy[t];
            if (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y])
                dfs(x, y, t);
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix;
        N = (int)matrix.size(), M = (int)matrix[0].size();

        visited = vector<vector<bool>> (N, vector<bool>(M, false));
        dfs(0, 0, 0);

        return ans;
    }
};