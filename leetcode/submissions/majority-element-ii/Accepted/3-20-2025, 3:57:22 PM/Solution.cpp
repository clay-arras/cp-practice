// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, candidate1 = 129392810;
        int count2 = 0, candidate2 = 480981233;

        int N = (int)nums.size();
        for (int i=0; i<N; ++i) {
            if (count1 == 0 && nums[i] != candidate2) {
                candidate1 = nums[i];
                count1++;
            } else if (count2 == 0 && nums[i] != candidate1) {
                candidate2 = nums[i];
                count2++;
            } else if (candidate1 != nums[i] && candidate2 != nums[i]) {
                count1--;
                count2--;
            } else {
                count1 += (nums[i] == candidate1 ? 1 : 0);
                count2 += (nums[i] == candidate2 ? 1 : 0);
            }
        }

        vector<int> ans;
        count1 = 0, count2 = 0;
        for (int i=0; i<N; i++) {
            if (nums[i] == candidate1) count1++;
            if (nums[i] == candidate2) count2++;
        }
        if (count1 > N/3) ans.push_back(candidate1);
        if (count2 > N/3) ans.push_back(candidate2);
        return ans;
    }
};