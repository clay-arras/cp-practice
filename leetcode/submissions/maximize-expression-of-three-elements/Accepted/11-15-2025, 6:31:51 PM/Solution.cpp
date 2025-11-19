// https://leetcode.com/problems/maximize-expression-of-three-elements

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int N = (int)nums.size();
        int ans = -INT_MAX;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                for (int k=j+1; k<N; k++) {
                    ans = max(ans, nums[i] + nums[j] - nums[k]);
                    ans = max(ans, nums[i] - nums[j] + nums[k]);
                    ans = max(ans, - nums[i] + nums[j] + nums[k]);
                }
            }
        }

        return ans;
    }
};