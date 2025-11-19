// https://leetcode.com/problems/maximum-score-after-splitting-a-string

class Solution {
public:
    int maxScore(string s) {
        map<char, int> n;
        for (auto c : s)
            n[c]++;

        map<char, int> m;
        int N = (int)s.size();
        int ans = 0;
        for (int i=0; i<N; i++) {
            m[s[i]]++;
            if (i != N - 1)
                ans = max(ans, m['0'] + n['1'] - m['1']);
        }
        return ans;
    }
};