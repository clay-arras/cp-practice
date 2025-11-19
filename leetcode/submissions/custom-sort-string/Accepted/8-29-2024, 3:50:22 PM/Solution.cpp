// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> m;
        for (int i=0; i<(int)order.size(); i++)
            m[order[i]] = i;
        sort(s.begin(), s.end(), [&](char a, char b) {
            return m[a] < m[b];
        });
        return s;
    }
};