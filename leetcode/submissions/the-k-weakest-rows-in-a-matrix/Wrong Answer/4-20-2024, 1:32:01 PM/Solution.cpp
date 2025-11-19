// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> ans;

        int N = (int)mat.size();
        for (int i=0; i<N; i++) {
            int ones = 0;
            for (auto j : mat[i]) ones += j;
            ans.push_back({ones, i});
        }

        sort(ans.begin(), ans.end());
        vector<int> ret;
        for (auto [f, s] : ans) {
            ret.push_back(s);
        }
        return ret;
    }
};