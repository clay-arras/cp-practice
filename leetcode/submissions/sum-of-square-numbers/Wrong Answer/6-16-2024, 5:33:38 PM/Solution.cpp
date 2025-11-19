// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        map<int, int> m;
        for (int i=0; i<=sqrt(c/2)+1; i++) {
            m[i*i]++;
            if (m[c - i*i])
                return true;
        }
        return false;
    }
};