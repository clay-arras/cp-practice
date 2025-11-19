// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = (int)height.size();

        int ans = 0;
        for (int l=0, r=N-1; l<r;) {
            ans = max(ans, (r-l) * min(height[r], height[l]));
            if (height[r] < height[l]) r--;
            else l++;
        }
        return ans;
    }
};