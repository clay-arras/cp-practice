// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> abit(a), bbit(b), cbit(c);
        int ans = 0;
        for (int i=0; i<32; i++) {
            if ((abit[i] | bbit[i]) != cbit[i]) 
                ans += abit[i] + bbit[i] + cbit[i];
        }
        return ans;
    }
};