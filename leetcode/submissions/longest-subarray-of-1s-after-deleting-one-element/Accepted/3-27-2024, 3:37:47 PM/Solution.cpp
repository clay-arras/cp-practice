// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        nums.push_back(0);
        int N = (int)nums.size();

        int l=0, r=1;
        bool z = false;
        for (r=1; r<N-1; r++) {
            if (nums[r] == 0 && z) {
                break;
            } else if (nums[r] == 0) {
                z = true;
            }
        }
        cout << l << " " << r << endl;

        int ans = r - l;
        for (; l<N-1 && r<N-1; ) {
            r++;
            while (r<N-1 && nums[r] == 1) r++;
            l++;
            while (l<N-1 && nums[l] == 1) l++;
            cout << l << " " << r << endl;
            ans = max(ans, r - l);
        }

        return ans - 2;
    }
};