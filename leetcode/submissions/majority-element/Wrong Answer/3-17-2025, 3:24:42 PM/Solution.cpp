// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            } else {
                count += (candidate == num ? 1 : -1);
            }
        }

        return candidate;
    }
};