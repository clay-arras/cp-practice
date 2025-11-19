// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(26, 0), t_cnt(26, 0);
        for (char c : t)    
            t_cnt[c-'A']++;

        auto is_same = [&]() {
            bool ok = true;
            for (int i=0; i<26; i++) 
                ok &= (t_cnt[i] <= cnt[i]);
            return ok;
        };

        int N = (int)s.size();
        string mn = s + "#";
        for (int r=0, l=0; r<N; r++) { 
            cnt[s[r]-'A']++;
            while (l<r && is_same()) {
                cnt[s[l]-'A']--;
                if (!is_same()) {
                    cnt[s[l]-'A']++;
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