// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> m;
        for (int i=0; i<(int)order.size(); i++)
            m[order[i]] = i;
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (m.count(a) && m.count(b))
                return m[a] < m[b];
            return a < b;
        });
        return s;
    }
};