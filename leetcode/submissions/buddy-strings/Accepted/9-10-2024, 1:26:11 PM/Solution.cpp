// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int N = (int)s.size();
        if ((int)s.size() != (int)goal.size())
            return false;
        
        int cnt = 0;
        map<char, int> m, n;
        for (int i=0; i<N; i++) {
            if (s[i] == goal[i])
                cnt++;
            else {
                m[s[i]]++;
                m[goal[i]]--;
            }
            n[s[i]]++;
        }
        bool ok1 = false;
        for (auto [k, v] : m)
            ok1 |= v;
        
        bool ok2 = false;
        for (auto [k, v] : n)
            ok2 |= (v >= 2);
        
        return (cnt + 2 == N && !ok1) || (s == goal && ok2);
    }
};