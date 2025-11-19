// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int mxVal = -1;
        int leftIndex = -1, rightIndex = -1;
        int N = (int)height.size();
        for (int i=0; i<N; i++) {
            if (height[i] >= mxVal) {
                mxVal = height[i];
                rightIndex = i;
            }
        }
        for (int i=N-1; i>=0; i--) {
            if (height[i] == mxVal) {
                leftIndex = i;
                break;
            }
        }

        int ans = 0;

        int curMax = -1;
        for (int i=0; i<N; i++) {
            if (i == rightIndex)
                break;
            ans += max(0, curMax - height[i]);
            curMax = max(curMax, height[i]);
        }
        curMax = -1;
        for (int i=N-1; i>=0; i--) {
            if (i == leftIndex)
                break;
            ans += max(0, curMax - height[i]);
            curMax = max(curMax, height[i]);
        }
        return ans;
    }
};