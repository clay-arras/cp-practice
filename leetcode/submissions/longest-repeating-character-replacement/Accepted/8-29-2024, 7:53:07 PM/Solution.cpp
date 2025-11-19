// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> m;
        multiset<int> ms;

        int N = (int)s.size();
        int ans = 0;
        for (int l=0, r=0; r<N; r++) {
            auto val = ms.find(m[s[r]]);
            if (val != ms.end())
                ms.erase(val);
            m[s[r]]++;
            ms.insert(m[s[r]]);
            while (l < r && !ms.empty() && r-l+1 - *ms.rbegin() > k) {
                auto val = ms.find(m[s[l]]);
                if (val != ms.end())
                    ms.erase(val);
                m[s[l]]--;
                ms.insert(m[s[l]]);
                l++;
            }
            ans = max(ans, r-l+1);
            ;
        }
        return ans;
    }
};