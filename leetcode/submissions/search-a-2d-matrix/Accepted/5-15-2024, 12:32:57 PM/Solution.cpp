// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:

    int N, M, t;
    vector<vector<int>> g;
    int lastTrue(int l, int r) {
        l--;
        for (int diff=r-l; diff>0; diff/=2) 
            while (l+diff <= r && ok(l+diff))
                l += diff;
        return l;
    }

    bool ok(int k) {
        if (k >= 0 && k < N*M) {
            int i = k/M, j = k%M;
            return g[i][j] <= t;
        }
        return (k <= N*M); 
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        N = (int)matrix.size(), M = (int)matrix[0].size();
        t = target, g = matrix;

        for (int i=0; i<N*M; i++) 
            cout << i/M << " " << i%M << endl;
            // cout << ok(i);

        int val = lastTrue(0, N*M-1);
        if (val >= 0 && val < N*M)
            return matrix[val/M][val%M] == target;
        return false;
    }
};