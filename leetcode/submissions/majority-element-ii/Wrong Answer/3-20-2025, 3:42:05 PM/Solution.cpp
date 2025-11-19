// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<> distrib(-INT_MAX, INT_MAX);

        int count1 = 0;
        int candidate1 = -80211;

        int N = (int)nums.size();
        if (N < 3) {
            auto i = std::unique(nums.begin(), nums.end());
            nums.resize(std::distance(nums.begin(), i));
            return nums;
        }

        for (int i=0; i<N; ++i) {
            if (count1 == 0) {
                candidate1 = nums[i];
                count1 += 2;
            } else {
                count1 += (nums[i] == candidate1 ? 2 : -1);
            }
        }
        vector<int> ans;
        int cnt1 = 0;
        for (int i=0; i<N; i++) 
            if (nums[i] == candidate1) cnt1++;
            
        if (cnt1 > N/3)
            ans.push_back(candidate1);

        int count2 = 0;
        int candidate2 = -919741;

        if (count1 == 0) {
            return {};
        }
        for (int i=0; i<N; i++)
            if (nums[i] == candidate1)
                nums[i] = distrib(rng);

        for (int i=0; i<N; ++i) {
            if (count2 == 0) {
                candidate2 = nums[i];
                count2 += 1;
            } else {
                count2 += (nums[i] == candidate2 ? 1 : -1);
            }
        }

        int cnt2 = 0;
        for (int i=0; i<N; i++) 
            if (nums[i] == candidate2) cnt2++;

        if (cnt2 > N/3)
            ans.push_back(candidate2);
        return ans;
    }
};