// https://leetcode.com/problems/find-mirror-score-of-a-string

class Solution {
public:
    long long calculateScore(string s) {
        // set, to find
        // property of set, always find the biggest/smallest
        // after done, remove from set (else add to set)

        set<pair<char, int>> st;
        const auto mir = [](char c) {
            return (char)((25-(c-'a'))+'a');
        };

        long long ans = 0;
        int N = (int)s.size();
        for (int i=0; i<N; i++) {
            auto it = st.lower_bound({mir(s[i]), -i});
            if (it != st.end() && it->first == mir(s[i])) {
                ans += i + it->second;
                st.erase(it);
                continue;
            } 
            st.insert({s[i], -i});
        }

        return ans;
    }
};