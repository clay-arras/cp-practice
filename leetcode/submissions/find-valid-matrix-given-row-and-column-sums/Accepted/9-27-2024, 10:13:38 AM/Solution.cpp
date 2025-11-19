// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int N = (int)rowSum.size(), M = (int)colSum.size();
        vector<vector<int>> ans(N, vector<int> (M, 0));
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                int t = min(rowSum[i], colSum[j]);
                ans[i][j] = t;
                rowSum[i] -= t;
                colSum[j] -= t;

                
            }
        }
        return ans;
    }
};