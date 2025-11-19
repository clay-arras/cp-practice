// https://leetcode.com/problems/sort-the-matrix-diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int N = (int)mat.size(), M = (int)mat[0].size();
        vector<vector<int>> ans = mat;
        auto cmp = [&](pair<int, int> x, pair<int, int> y) {
            return mat[x.first][x.second] < mat[y.first][y.second];
        };
        
        for (int i=0; i<N; i++) {
            vector<pair<int, int>> crds;
            for (int x=i, y=0; x<N && y<M; x++, y++) 
                crds.push_back({x, y});
            sort(crds.begin(), crds.end());
            for (int k=0, x=i, y=0; x<N && y<M; k++, x++, y++) 
                ans[x][y] = mat[crds[k].first][crds[k].second];
                
        }
        for (int j=1; j<M; j++) {
            vector<pair<int, int>> crds;
            for (int x=0, y=j; x<N && y<M; x++, y++) 
                crds.push_back({x, y});
            sort(crds.begin(), crds.end());
            for (int k=0, x=0, y=j; x<N && y<M; k++, x++, y++) 
                ans[x][y] = mat[crds[k].first][crds[k].second];
        }
        return ans;
    }
};