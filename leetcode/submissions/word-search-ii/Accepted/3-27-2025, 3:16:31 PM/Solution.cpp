// https://leetcode.com/problems/word-search-ii

#include <vector>
#include <string>
#include <unordered_set>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int N, M;
    unordered_set<string> st, ans;
    vector<vector<char>> g;
    
    inline int idx(int i, int j) {
        return i * M + j;
    }
    
    void dp(string s, bitset<144> vis, int i, int j) {
        if ((int)s.size() > 10)
            return;
        if (st.count(s))
            ans.insert(s);
        
        vis.set(idx(i, j));
        
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !vis.test(idx(nx, ny)))
                dp(s + g[nx][ny], vis, nx, ny);
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        g = board;
        N = board.size();
        M = board[0].size();
        bitset<144> vis;  
        
        for (const string &s : words)
            st.insert(s);
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                dp(string(1, g[i][j]), vis, i, j);
        
        return vector<string>(ans.begin(), ans.end());
    }
};
