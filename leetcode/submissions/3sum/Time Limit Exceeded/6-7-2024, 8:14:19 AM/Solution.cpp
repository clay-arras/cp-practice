// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        map<int, int> m;
        map<vector<int>, int> exists;
        vector<vector<int>> ans;
        int N = (int)nums.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (m[-(nums[i] + nums[j])]) {
                    vector<int> a = {nums[i], nums[j], -(nums[i] + nums[j])};
                    sort(a.begin(), a.end());
                    if (!exists[a])
                        ans.push_back(a);
                    exists[a]++;
                }
            }
            m[nums[i]]++;
        }
        return ans;
    }
};