// https://leetcode.com/problems/word-search-ii

class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int N, M;
    unordered_set<string> st, ans;
    vector<vector<char>> g;
    void dp (string s, vector<vector<bool>> vis, int i, int j) {
        if ((int)s.size() > 10)
            return;
        if (st.contains(s))
            ans.insert(s);
        vis[i][j] = true;

        for (int k=0; k<4; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny]) 
                dp(s + g[nx][ny], vis, nx, ny);
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        g = board;
        N = (int)g.size(), M = (int)g[0].size();
        vector<vector<bool>> vis(N, vector<bool> (M, false));
        for (string s : words)
            st.insert(s);

        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                dp(string(1, g[i][j]), vis, i, j);

        vector<string> ret;
        for (auto i : ans)
            ret.push_back(i);
        return ret;
    }
};