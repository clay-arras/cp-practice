// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int i=0; i<=33; i++) {
            long long targ = num1 - 0LL - i*1LL*num2;
            if (targ >= 0 && __builtin_popcount(targ) <= i && targ != 0) {
                return i;
            }
        }
        return -1;
    }
};