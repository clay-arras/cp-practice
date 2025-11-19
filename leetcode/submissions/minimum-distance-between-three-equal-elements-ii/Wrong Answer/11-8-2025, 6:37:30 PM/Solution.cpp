// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int N = (int)nums.size();
        unordered_map<int, set<int>> m;

        for (int i=0; i<N; i++)
            m[nums[i]].insert(i);

        int ans = INT_MAX;
        for (auto [k, v] : m) {
            if ((int)v.size() < 3) continue;
            ans = min(ans, 2*(*v.rbegin() - *v.begin()));
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};