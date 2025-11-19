// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int N = (int)s.size();
        if ((int)s.size() != (int)goal.size())
            return false;
        
        int cnt = 0;
        map<char, int> m;
        for (int i=0; i<N; i++) {
            if (s[i] == goal[i])
                cnt++;
            else {
                m[s[i]]++;
                m[goal[i]]--;
            }
        }
        bool ok = false;
        for (auto [k, v] : m)
            ok |= v;
        
        return (cnt + 2 == N && !ok) || s == goal;
    }
};