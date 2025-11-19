// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int N = (int)nums.size();
        if (N < 3) return -1;
        
        int ans = INT_MAX;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                for (int k=j+1; k<N; k++) {
                    if (nums[i] == nums[j] && nums[j] == nums[k])
                        ans = min(ans, abs(i-j) + abs(j-k) + abs(k-i));
                }
            }
        }
        return ans;
    }
};