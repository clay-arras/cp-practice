// https://leetcode.com/problems/guess-the-number-using-bitwise-questions-i

/** 
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int ans = 0;
        for (int i=0; i<31; i++) {
            ans |= (1LL << i) * commonSetBits(1LL << i);
        }

        return ans;
    }
};