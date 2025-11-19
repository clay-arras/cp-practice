// https://leetcode.com/problems/minimum-increment-to-make-array-unique

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int N = (int)nums.size();
        map<int, int> m;
        int ans = 0;
        for (int i=0; i<N; i++) {
            while (m[nums[i]]) {
                nums[i]++;
                ans++;
            }
            m[nums[i]]++;
        }
        return ans;
    }
};