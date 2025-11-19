// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int N = (int)nums.size();
        unordered_map<int, set<int>> m;


        int ans = INT_MAX;
        for (int i=0; i<N; i++) {
            if ((int)m[nums[i]].size() >= 2) {
                int a = *m[nums[i]].rbegin();
                int b = *next(m[nums[i]].rbegin(), 1);
                ans = min(ans, 2*(i - b));
            }
            m[nums[i]].insert(i);
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};