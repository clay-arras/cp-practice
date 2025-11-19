// https://leetcode.com/problems/find-the-largest-almost-missing-integer

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int N = (int)nums.size();

        unordered_map<int, int> m;
        for (int i=k; i<=N; i++) {
            int ed = i;
            int st = i-k;
            unordered_set<int> s;
            for (int j=st; j<ed; j++)
                s.insert(nums[j]);
            for (int j : s)
                m[j]++;
        }

        int ans = -1;
        for (auto [k, v] : m) 
            if (v == 1)
                ans = max(ans, k);
        return ans;
    }
};