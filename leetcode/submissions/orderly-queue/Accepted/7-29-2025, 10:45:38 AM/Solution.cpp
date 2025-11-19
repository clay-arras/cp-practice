// https://leetcode.com/problems/orderly-queue

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            int N = (int)s.size();
            string ans = s;
            for (int i=0; i<N; i++) {
                ans = min(ans, s.substr(i, string::npos) + s.substr(0, i));
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};