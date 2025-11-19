// https://leetcode.com/problems/make-array-elements-equal-to-zero

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int N = (int)nums.size();

        int ans = 0;
        for (int i=0; i<N; i++) {
            int l = 0;
            int r = 0;

            if (nums[i] == 0) {
                for (int j=0; j<i; j++) 
                    l += nums[j];
                for (int j=i+1; j<N; j++) 
                    r += nums[j];
                ans += 2*(l == r);
            }
        }
        return ans;
    }
};