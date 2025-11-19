// https://leetcode.com/problems/number-of-unique-xor-triplets-i

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int N = (int)nums.size();
        if ((int)nums.size() == 2)
            return 2;
        return (1 << (int)(floor(log2(N)) + 1));
    }
};