// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int N = (int)nums.size();
        vector<int> ans(N, -1);
        for (int i=0; i<N; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i=0; i<N; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};