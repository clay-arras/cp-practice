// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int N = (int)s.size();
        int ans = 0;
        for (int l=0, r=0; r<N; r++) {
            m[s[r]]++;
            while (m[s[r]] > 1) {
                m[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};