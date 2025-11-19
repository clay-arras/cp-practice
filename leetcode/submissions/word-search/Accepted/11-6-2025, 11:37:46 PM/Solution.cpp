// https://leetcode.com/problems/word-search

class Solution {
public:
    vector<vector<int>> visited;
    vector<vector<char>> g;
    
    int N, M, Sz;
    string s;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    bool ans = false;
    
    void dfs(int i, int j, int idx) {
        if (g[i][j] != s[idx])
            return;
        if (idx == Sz-1)
            ans = true;
        
        visited[i][j] = true;
        for (int k=0; k<4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y])
                dfs(x, y, idx+1);
        }
        visited[i][j] = false;
    } 
    
    bool exist(vector<vector<char>>& board, string word) {
        N = (int)board.size(), M = (int)board[0].size(); 
        Sz = (int)word.size();
        
        g = board;
        s = word;
        
        visited = vector<vector<int>>(N, vector<int>(M, 0));
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++) 
                dfs(i, j, 0);
        
        return ans;
    }
};