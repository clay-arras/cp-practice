// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        nums.insert(nums.begin(), 0);
        nums.push_back(0);
        int N = (int)nums.size();

        int l=0, r=1;
        for (r=1; r<N && k > 0; r++) {
            if (nums[r] == 0) k--; 
        }

        // for (int i=0; i<N; i++) {
        //     cout << nums[i];
        //     if (i == r)
        //         cout << ".";
        // }
        // cout << endl;

        int ans = r - l;
        for (; l<N && r<N;) {
            r++;
            while (r<N && nums[r]==1) r++;
            l++;
            while (l<N && nums[l]==1) l++;
            ans = max(ans, r - l);
        }

        return ans - 1;
    }
};