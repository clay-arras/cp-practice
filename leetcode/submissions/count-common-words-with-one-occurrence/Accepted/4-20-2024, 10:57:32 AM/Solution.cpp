// https://leetcode.com/problems/count-common-words-with-one-occurrence

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> m1;
        for (auto s : words1) {
            m1[s]++;
        }
        map<string, int> m2;
        for (auto s : words2) {
            if (m1[s] == 1) 
                m2[s]++;
        }
        int count = 0;
        for (auto [k, v] : m2) {
            if (v == 1)
                count++;
        }
        return count;
    }
};