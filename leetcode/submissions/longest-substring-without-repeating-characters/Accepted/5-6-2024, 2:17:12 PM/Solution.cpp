// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int ans = 0;

        for (int l=0, r=0, N = (int)s.size(); r<N; r++) {
            m[s[r]]++;
            while (m[s[r]] > 1) 
                m[s[l++]]--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};