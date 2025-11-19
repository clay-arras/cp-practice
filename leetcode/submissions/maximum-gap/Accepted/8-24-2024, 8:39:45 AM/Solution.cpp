// https://leetcode.com/problems/maximum-gap

class Solution {
public:
    int pos(int x, int fact) {
        return ((int)(x / pow(10, fact)) % 10);
    }

    void countSort(vector<int>& nums, int fact) {
        int N = (int)nums.size();
        vector<int> count(10, 0);
        for (int i : nums) 
            count[pos(i, fact)]++;
        for (int i=1; i<10; i++)
            count[i] += count[i-1];
        
        vector<int> sort(N, 0);
        for (int i=N-1; i>=0; i--) 
            sort[(count[pos(nums[i], fact)]--)-1] = nums[i];
        nums = sort;
    }

    int maximumGap(vector<int>& nums) {
        int N = (int)nums.size();
        int MN = *min_element(nums.begin(), nums.end());
        for (int& i : nums) i += MN;
        int MX = *max_element(nums.begin(), nums.end());

        for (int cnt=0; cnt<log10(MX)+1; cnt++) 
            countSort(nums, cnt);

        int ans = 0;
        for (int i=1; i<N; i++)
            ans = max(ans, nums[i] - nums[i-1]);
        
        return ans;
    }
};