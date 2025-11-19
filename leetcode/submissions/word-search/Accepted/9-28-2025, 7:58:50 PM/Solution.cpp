// https://leetcode.com/problems/word-search

class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vector<vector<bool>> visited;
    vector<vector<char>> b;
    int N, M;
    string tar;

    bool ok = false;

    void dfs(int i, int j, int depth) { 
        if (b[i][j] != tar[depth])
            return;
        if (depth == tar.size()-1) {
            ok = true;    
            return;
        }
        assert(depth < tar.size());

        visited[i][j] = true;
        for (int k=0; k<4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y])
                dfs(x, y, depth+1);
        }

        visited[i][j] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        tar = word;

        N = (int)b.size(), M = (int)b[0].size();
        visited = vector<vector<bool>>(N, vector<bool> (M, false));

        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                dfs(i, j, 0);

        return ok;
    }
};