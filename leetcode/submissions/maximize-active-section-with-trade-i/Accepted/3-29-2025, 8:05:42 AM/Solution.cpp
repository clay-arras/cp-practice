// https://leetcode.com/problems/maximize-active-section-with-trade-i

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int N = (int)s.size();
        int curr = 0;
        for (int i=0; i<N; i++)
            curr += s[i] - '0';
        int prev = curr;

        s = "1" + s + "1";
        N = (int)s.size();
        int activ = 0;
        
        int l = 0, r = 0;
        while (s[l] == '1')
            l++;
        r = l;
        for (; r<N; r++) {
            while (!activ || s[r] == '1') {
                activ += (s[r] == '1');
                r++;
            }
            if (r >= N)
                break;
            curr = max(curr, prev + r-l+1 - activ);
            while (activ && s[r+1] == '1') {
                activ -= (s[l] == '1');
                l++;
            }
        }

        return curr;
    }
};