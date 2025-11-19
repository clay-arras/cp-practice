// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        for (long long i=1; i<=(1LL << 31); i<<=1) 
            ans += (bool)(i & n);

        return ans;
    }
};