// https://leetcode.com/problems/count-number-of-trapezoids-i

class Solution {
public:
    const static int MOD = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> m;
        for (auto i : points) 
            m[i[1]].push_back(i[0]);
        vector<int> ys;
        for (auto [k, v] : m)
            ys.push_back(k);
        
        int ans = 0;
        int res = 0;
        for (int i=0; i<(int)ys.size(); i++) {
            int l1 = (int)m[ys[i]].size();
            long long cl1 = l1 * (l1-1) / 2;
            ans = (ans + (cl1 * res)) % MOD;
            res += cl1;
        }
        return ans;
    }
};