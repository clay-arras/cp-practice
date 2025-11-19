// https://leetcode.com/problems/longest-balanced-subarray-i

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int N = (int)nums.size();

        int ans = 0, r=0;
        for (int l=0; l<N; l++) {
            unordered_map<int, int> e, o;
            for (int r=l; r<N; r++) {
                if (nums[r] % 2) o[nums[r]]++;
                else e[nums[r]]++;

                if ((int)e.size() == (int)o.size())
                    ans = max(ans, r-l+1);
            }
        }

        return ans;
    }
};