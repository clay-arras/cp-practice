// https://leetcode.com/problems/matrix-block-sum

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int N = (int)mat.size(), M = (int)mat[0].size();
        vector<vector<int>> ans(N, vector<int>(M, 0)), pref(N+1, vector<int>(M+1, 0));
        
        for (int i=1; i<=N; i++) 
            for (int j=1; j<=M; j++) 
                pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i-1][j-1];
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                ans[i][j] = (
                    pref[min(i+k+1, N)][min(j+k+1, M)] 
                    - pref[min(i+k+1, N)][max(j-k, 0)]
                    - pref[max(i-k, 0)][min(j+k+1, M)]
                    + pref[max(i-k, 0)][max(j-k, 0)]
                );
            }
        }
        return ans;
    }
};