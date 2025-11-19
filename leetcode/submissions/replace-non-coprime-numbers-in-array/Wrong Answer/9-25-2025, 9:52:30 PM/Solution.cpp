// https://leetcode.com/problems/replace-non-coprime-numbers-in-array

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int N = (int)nums.size();

        vector<int> ans;
        long long curr = nums[0];
        for (long long r=1; r<N; r++) {
            long long g = gcd(curr, nums[r]);
            if (g == 1) {
                ans.push_back(curr);
                curr = nums[r];
            } else {
                assert((nums[r] * curr) % g == 0);
                curr = (nums[r] * curr) / g;
            }
        }   
        ans.push_back(curr);


        vector<int> tmp;
        curr = ans[0];
        for (long long r=1; r<(int)ans.size(); r++) {
            long long g = gcd(curr, ans[r]);
            if (g == 1) {
                tmp.push_back(curr);
                curr = ans[r];
            } else {
                assert((ans[r] * curr) % g == 0);
                curr = (ans[r] * curr) / g;
            }
        }   
        tmp.push_back(curr);

        return tmp;
    }
};