// https://leetcode.com/problems/count-pairs-with-xor-in-a-range

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int N = (int)nums.size();
        auto lessThanK = [&](int k) {
            map<int, int> m;
            int ans = 0;
            for (int i=0; i<N; i++) {
                for (int j=0; j<=k; j++) 
                    ans += m[j^nums[i]];
                m[nums[i]]++;
            }
            return ans;
        };
        return lessThanK(high) - lessThanK(low-1);
    }
};