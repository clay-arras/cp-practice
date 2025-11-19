// https://leetcode.com/problems/sort-the-matrix-diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        int N = (int)mat.size(), M = (int)mat[0].size();
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                m[i-j].push(mat[i][j]);
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                mat[i][j] = m[i-j].top(); 
                m[i-j].pop();
            }
        }
        return mat;
    }
};