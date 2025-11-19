// https://leetcode.com/problems/longest-balanced-substring-i

class Solution {
public:
    int longestBalanced(string s) {
        int N = (int)s.size();

        vector<vector<int>> pref(N+1, vector<int>(26, 0));
        for (int i=0; i<N; i++) {
            pref[i+1] = pref[i];
            pref[i+1][s[i]-'a']++;
        }

        int ans = 1;
        for (int l=0; l<N; l++) {
            for (int r=l+1; r<N; r++) {
                int first = -1;
                for (int k=0; k<26; k++) {
                    int diff = pref[r+1][k] - pref[l][k];
                    if (diff != 0) {
                        if (first == -1) first = diff;
                        else if (first != diff) {
                            first = -1;
                            break;
                        }
                    }
                } 
                if (first != -1)
                    ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};