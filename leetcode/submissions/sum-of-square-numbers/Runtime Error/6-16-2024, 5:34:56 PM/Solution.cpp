// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        map<int, int> m;
        for (int i=0; i<=sqrt(c)+1; i++) {
            cout << i << endl;
            m[i*i]++;
            if (m[c - i*i])
                return true;
        }
        return false;
    }
};