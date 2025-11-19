// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> m;
        multiset<int> ms;

        int N = (int)s.size();
        int ans = 0;
        for (int l=0, r=0; r<N; r++) {
            ms.erase(m[s[r]]);
            m[s[r]]++;
            ms.insert(m[s[r]]);
            while (l < r && !s.empty() && r-l+1 - *ms.rbegin() > k) {
                ms.erase(m[s[l]]);
                m[s[l]]--;
                ms.insert(m[s[l]]);
                l++;
            }
            ans = max(ans, r-l+1);

        }
        return ans;
    }
};