// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        long long MX = *max_element(nums.begin(), nums.end());
        long long MN = *min_element(nums.begin(), nums.end());
        vector<long long> cnt(MX - MN + 1, 0);
        int N = (int)nums.size();

        for (int i=0; i<N; i++) 
            cnt[nums[i] - MN]++;
        
        for (long long i=1; i<(int)cnt.size(); i++)
            cnt[i] += cnt[i-1];
        
        vector<int> ans(N, 0);
        for (int i=(int)nums.size()-1; i>=0; i--) {
            nums[cnt[nums[i]-MN]-1] = ans[i];
            cnt[nums[i]-MN]--;
        }

        return ans;
    }
};