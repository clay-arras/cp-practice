// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cnt, t_cnt;
        for (char c : t)    
            t_cnt[c]++;

        auto is_same = [&]() {
            bool ok = true;
            for (int i=0; i<26; i++) 
                ok &= (t_cnt[i + 'a'] <= cnt[i + 'a']);
            for (int i=0; i<26; i++) 
                ok &= (t_cnt[i + 'A'] <= cnt[i + 'A']);
            return ok;
        };

        int N = (int)s.size();
        string mn = s + "#";
        for (int r=0, l=0; r<N; r++) { 
            cnt[s[r]]++;
            while (l<r && is_same()) {
                cnt[s[l]]--;
                if (!is_same()) {
                    cnt[s[l]]++;
                    break;
                }
                l++;
            }
            if (is_same() && r-l+1 <= (int)mn.size())
                mn = s.substr(l, r-l+1);
        }
        return (mn == s + "#" ? "" : mn); // might be slow
    }
};