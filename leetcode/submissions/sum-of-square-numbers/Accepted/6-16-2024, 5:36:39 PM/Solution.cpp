// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        map<long long, int> m;
        for (long long i=0; i<=sqrt(c)+1; i++) {
            m[i*i]++;
            if (m[c - i*i])
                return true;
        }
        return false;
    }
};