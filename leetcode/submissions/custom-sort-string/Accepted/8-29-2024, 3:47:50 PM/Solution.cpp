// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> m;
        for (char c : order)
            m[c]++;
        map<char, int> cnt;
        string ans = "";
        for (char c : s) {
            if (!m[c]) ans += c;
            else cnt[c]++;
        }
        for (char c : order) {
            while (cnt[c] > 0) {
                cnt[c]--;
                ans += c;
            }
        } 
        return ans;
    }
};