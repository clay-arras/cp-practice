// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int i=0; i<=33; i++) {
            int targ = num1 - i*num2;
            if (__builtin_popcount(targ) == i) 
                return i;
        }
        return -1;
    }
};