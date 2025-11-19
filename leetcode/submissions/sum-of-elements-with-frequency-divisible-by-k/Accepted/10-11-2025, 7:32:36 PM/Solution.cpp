// https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i : nums)
            m[i]++;

        int ans = 0;
        for (auto [t, v] : m)
            if (v % k == 0)
                ans += v*t;
        return ans;
    }
};