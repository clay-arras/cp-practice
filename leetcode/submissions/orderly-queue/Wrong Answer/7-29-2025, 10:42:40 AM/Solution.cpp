// https://leetcode.com/problems/orderly-queue

class Solution {
public:
    string orderlyQueue(string s, int k) {
        // when would you NOT want to do another operation? 
        sort(s.begin(), s.end());
        return s;
    }
};