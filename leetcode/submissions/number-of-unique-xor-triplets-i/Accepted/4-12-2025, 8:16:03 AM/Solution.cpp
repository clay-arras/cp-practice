// https://leetcode.com/problems/number-of-unique-xor-triplets-i

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int N = (int)nums.size();
        if (N <= 2)
            return N;
        return (1 << (int)(floor(log2(N)) + 1));
    }
};